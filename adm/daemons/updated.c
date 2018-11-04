// updated.c
// write by Doing Lu for user management
// because a user may does much association with others,
// so I must assure all the data keep consistant

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <room.h>

inherit F_SAVE;

// data need save
mixed title_base;

string query_save_file() { return DATA_DIR "pinfo"; }

void remove_title(object ob);
void set_title(object ob);
object global_find_player(string user);
void global_destruct_player(object ob, int raw);

void create()
{
        seteuid(getuid());
        restore();

        if (arrayp(title_base))
                title_base = filter_array(title_base, (: arrayp($1) && sizeof($1) == 2 :));
        else
                title_base = 0;
}

#define LUBAN           "/adm/npc/luban"
#define RING_DIR        "/data/item/ring/"

// check the user's data when login
void check_user(object ob)
{
	mapping my;
        mapping skill_status;
        string *sname;
        int combat_exp;
        int level;
        int i;
	mapping party;

	my = ob->query_entire_dbase();

	if (ob->query("family/generation") == 0)
		ob->delete("family");

	if (ob->query("gender") == "����")
		ob->set("class", "eunach");

        if ((int)ob->query("combat/today/which_day") != time() / 86400)
                ob->delete("combat/today");

	if (mapp(party = my["party"]) && stringp(party["party_name"]))
		party["party_name"] = filter_color(party["party_name"]);

        // ��¼����
        NAME_D->map_name(ob->query("name"), ob->query("id"));

        // �����������м�ʱ��
        reset_eval_cost();

        // ����ƺ�
        set_title(ob);

        // ���� killer ����Ϣ
        ob->update_killer();

	if (wizardp(ob)) return;

	if (undefinedp(my["eff_jing"]))  my["eff_jing"] = my["max_jing"];
	if (undefinedp(my["eff_qi"])) my["eff_qi"] = my["max_qi"];
	if (my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];
	if (my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
	if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
	if (my["jing"] > my["eff_jing"]) my["jing"] = my["eff_jing"];
	if (my["neili"] > my["max_neili"] * 2) my["neili"] = my["max_neili"] * 2;

	combat_exp = (int)ob->query("combat_exp");
	if (! mapp(skill_status = ob->query_skills())) return;
	sname  = keys(skill_status);

	for (i = 0; i < sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
                if (file_size(SKILL_D(sname[i]) + ".c") == -1)
                {
                        tell_object(ob, "No such skill:" + sname[i] + "\n");
                        continue;
                }

                if (SKILL_D(sname[i])->type() == "martial")
                {
            		while (level &&
			       (level - 1) * (level -1 ) * (level - 1) / 10 > combat_exp)
            		       level--;
        
            		ob->set_skill(sname[i], level);
                }
	}
}

// clear the user's data
// when catalog parameter equal to "all", I will remove all
// the informatino of this user. This may be used when the
// user was purged.
string clear_user_data(string user, string cat)
{
        object login_ob;
        object ob;
        string couple_id;
        string path, file_name;
        string *dirs;
        object temp;
        string brothers;
        string bro_id;
        mapping bro;
        int flag;
        int i;

        // only root uid can does it
        if (previous_object() &&
            getuid(previous_object()) != ROOT_UID &&
            geteuid(previous_object()) != user)
                return "����Ȩ�������ҵ����ݡ�\n";

        // find the user's body
        seteuid(getuid());
        login_ob = 0;
        ob = find_player(user);
        if (! ob)
        {
                login_ob = new(LOGIN_OB);
                login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
                if (! ob)
                {
                        catch(destruct(login_ob));
                        return "��ʱ�޷�������Ҷ���\n";
                }

		if (! ob->restore())
                {
                        catch(destruct(login_ob));
                        catch(destruct(ob));
                        return "û�������ҡ�\n";
                }

        	ob->setup();
        }

        // no catalog? treat it as "all"
        if (! cat) cat = "all";
        flag = 0;

        // remove name information
        if (cat == "name" || cat == "all")
                NAME_D->remove_name(ob->query("name"), ob->query("id"));

        // remove room information
        if ((cat == "room" || cat == "all") &&
            mapp(ob->query("private_room")))
        {
                // Demolish the room of the user
                LUBAN->demolish_room(ob);
                flag++;
        }

        // remove marriage information
        if ((cat == "couple" || cat == "all") &&
            mapp(ob->query("couple")))
        {
                // clear the couple infomation

                // remove the ring
                file_name = RING_DIR + ob->query("id");
                if (file_size(file_name + ".c") > 0)
                {
                        if (temp = find_object(file_name))
                        {
                                if (environment(temp))
                                {
                                        message("vision", HIM + temp->name() +
                                                HIM "��Ȼ����һ�����̣������ˣ�\n" NOR,
                                                environment(temp));
                                }
                        }
                        DBASE_D->clear_object(file_name);
                }

                couple_id = ob->query("couple/id");
                ob->delete("couple");
                ob->delete("can_summon/wedding ring");
                flag++;
                if (couple_id) clear_user_data(couple_id, "couple");
        }

        // remove item information
        if (cat == "item" || cat == "all")
        {
                object item;
                // clear the all item
                path = ITEM_DIR + ob->query("id")[0..0] + "/";
                dirs = get_dir(path + ob->query("id") + "-*");
                for (i = 0; i < sizeof(dirs); i++)
                {
                        file_name = path + dirs[i];
                        if ((item = find_object(file_name)) &&
                            environment(item))
                        {
                                message("vision", HIM + item->name() +
                                        "��Ȼ����һ�����̣������ˣ�\n" NOR,
                                        environment(item));
                        }
                        DBASE_D->clear_object(file_name);
                        rm(file_name);
                }
        }

        // remove board information
        if (cat == "board" || cat == "all")
        {
                object *rooms;
                rooms = filter_array(children(CHAT_ROOM),
                                     (: clonep($1) && $1->query("owner_id") == $(user) :));
                for (i = 0; i < sizeof(rooms); i++)
                        destruct(rooms[i]);
                file_name = DATA_DIR + "board/chatroom_" + user + __SAVE_EXTENSION__;
                rm(file_name);
        }

        // remove haterd information
        if (cat == "hatred" || cat == "all")
        {
                // remove the hatred information about the
                // familys & leagues to this player
                FAMILY_D->remove_hatred(ob->query("id"));
                LEAGUE_D->remove_hatred(ob->query("id"));
        }

        // remove brothers information
        if (mapp(bro = ob->query("brothers")) &&
            (sscanf(cat, "brothers:%s", brothers) == 1 || cat == "all"))
        {
                // remove all the brothers information
                if (cat == "all") brothers = "all";

                // here, I remove the brothers information of
                // ob, when brothers equal to "all", then I
                // will remove all brothers for this ob, Does it
                // cause a BUG? I won't, because the ID "all"
                // can not be registered for this MUD.
                if (brothers == "all")
                {
                        foreach (bro_id in keys(bro))
                                // remove my brother's data for me
                                clear_user_data(bro_id, "brothers:" + ob->query("id"));

                        ob->delete("brothers");
                } else
                if (! undefinedp(bro[brothers]) != -1)
                {
                        // remove this brother
                        map_delete(bro, brothers);
                        if (sizeof(bro) < 1)
                                ob->delete("brothers");
                        else
                                ob->set("brothers", bro);
                }
                flag++;
        }

        // remove league information
        if (cat == "league" || cat == "all")
        {
                // remove the user's league info
                LEAGUE_D->remove_member_from_league(ob);
                ob->delete("league");
        }

        // remove title information
        if (cat == "title" || cat == "all")
                remove_title(ob);

        // save the data of the user
        if (flag) ob->save();

        // Destrut the object if create temporate
        if (login_ob)
        {
                catch(destruct(login_ob));
                catch(destruct(ob));
        }

        return "�ɹ���\n";
}

// remove an user
string remove_user(string user)
{
        object ob;
        string result;

        // destruct the user object
        if (ob = find_player(user))
        {
                if (ob->query_temp("link_ob"))
                        catch(destruct(ob->query_temp("link_ob")));
                catch(destruct(ob));
        }

        // Remove the user from wizlist if the user was wizard
        SECURITY_D->set_status(user, "(player)");

        // clear the data of user first
        result = clear_user_data(user, "all");

        // remove the file of the user
	rm(DATA_DIR + "login/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
	rm(DATA_DIR + "user/" + user[0..0] + "/" + user + __SAVE_EXTENSION__);
}

// user born
void born_player(object me)
{
        mixed files;
        int i;
        string special;
        string msg;

        msg = HIG "�����������ļ����У�" NOR;

        // �鿴���е����⼼���ļ�
        files = get_dir("/kungfu/special/");
        me->delete("special_skill");

        if (sizeof(files))
        {
                // �������еļ����ļ�
                for (i = 0; i < sizeof(files); i++)
                        sscanf(files[i], "%s.c", files[i]);

                // �����������������ų�
                files -= ({ "lighting" });

                // �Ը񲻷������ŭ֮��
                if (me->query("character") != "��������"
                   && me->query("character") != "�ĺ�����")
                        files -= ({ "wrath" });

                // �������� < 26 ��������Ѫ��
                if (me->query("str") < 26)
                        files -= ({ "strength" });

                // �������� < 26 ���������
                if (me->query("int") < 26)
                        files -= ({ "intellect" });

                // ������� < 26 ������������
                if (me->query("con") < 26)
                        files -= ({ "constitution" });

                // ������ < 26 ������������
                if (me->query("dex") < 26)
                        files -= ({ "dexterity" });

                // ������ò < 20 ����������פ
                if (me->query("per") < 20)
                        files -= ({ "youth" });

                // �����������
                files -= ({"emperor"});

                // ��õ�һ���
                special = files[random(sizeof(files))];
                me->set("special_skill/" + special, 1);

                msg += SPECIAL_D(special)->name();

                files -= ({ special });
                if (sizeof(files) && random(100) == 1)
                {
                        // ��õڶ����
                        special = files[random(sizeof(files))];
                        me->set("special_skill/" + special, 1);
                        msg += HIG "��" NOR + SPECIAL_D(special)->name();

                        files -= ({ special });
                        if (sizeof(files) && random(30) == 1)
                        {
                                // ��õ������
                                special = files[random(sizeof(files))];
                                me->set("special_skill/" + special, 1);
                                msg += HIG "��" NOR + SPECIAL_D(special)->name();
                        }
                }

                // ����Ѫ������1������
                if (me->query("special_skill/strength"))
                        me->add("str", 1);

                // ���������1������
                if (me->query("special_skill/intellect"))
                        me->add("int", 1);

                // ������������1�����
                if (me->query("special_skill/constitution"))
                        me->add("con", 1);

                // ������������1����
                if (me->query("special_skill/dexterity"))
                        me->add("dex", 1);

                msg += HIG "��\n" NOR + HIC "�����Դ����κ����ʣ���������"
                       "�Ķ��츳����(" HIY "help gift" NOR + HIC ")���ܡ�\n"
                       NOR;
                me->start_call_out((: call_other, __FILE__, "notice_player",
                                      me, msg :), 0);
        }
}

// notice user a piece of message, delay call by born user
void notice_player(object me, string msg)
{
        tell_object(me, msg);
}

// query title dbase
mixed query_title_base()
{
        if (! is_root(previous_object()))
                return 0;

        return title_base;
}

// set title dbase
mixed set_title_base(mixed ts)
{
        if (! is_root(previous_object()))
                return 0;

        title_base = ts;
}

// ���ĳ����ҵ� title
void remove_title(object ob)
{
        int i;

        if (! arrayp(title_base) || ! ob->query("granted_title"))
                return;

        ob->delete_temp("title");
        ob->delete("granted_title");

        for (i = 0; i < sizeof(title_base); i++)
        {
                // �������е� title
                if (title_base[i][1] == ob->query("id"))
                        // ȥ��title
                        title_base[i][1] = 0;
        }
        save();
        return;
}

// ����ĳ����ҵ� title
void set_title(object ob)
{
        string id;
        int i;

        if (! arrayp(title_base) || ! ob->query("granted_title"))
                return;

        id = ob->query("id");
        for (i = 0; i < sizeof(title_base); i++)
                if (title_base[i][1] == id)
                {
                        // ����title
                        ob->set_temp("title", title_base[i][0]);
                        return;
                }

        // ����û���û�з���ĳƺ�
        ob->delete("granted_title");
}

// Ѱ�һ����ĳһ�����
// �������������Ҫ������Щ�����ߵ���ң������ʹ�øú���
// �������ҵ��벢�ҽ����޸ģ���ע�⣺�޸�����Ժ�������
// ������ң�����ʹ�� global_destruct_player �������������
// ��û�е������������������ҵĶ�ʱ�����Զ�������ҡ�
object global_find_player(string user)
{
        object ob;
        object login_ob;

        ob = find_player(user);
        if (! ob)
        {
                login_ob = new(LOGIN_OB);
                login_ob->set("id", user);
		ob = LOGIN_D->make_body(login_ob);
                if (! ob)
                {
                        catch(destruct(login_ob));
                        return 0;
                }

		if (! ob->restore())
                {
                        catch(destruct(login_ob));
                        catch(destruct(ob));
                        return 0;
                }

        	ob->set_temp("temp_loaded", 1);
                ob->start_call_out(bind((: call_other, __FILE__, "global_destruct_player", ob, 0 :), ob), 0);
                catch(destruct(login_ob));
        }

        return ob;
}

// ����һ���� UPDATE_D ��������
void global_destruct_player(object ob, int raw)
{
        if (objectp(ob) && ob->query_temp("temp_loaded"))
        {
                if (raw) ob->save();
                destruct(ob);
        }
}
