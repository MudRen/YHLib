#pragma optimize
#pragma save_binary

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <armor.h>

// flag of func:look_all_inventroy_of_room/ret_str
#define SHOW_IMMEDIATELY        0
#define RETURN_RESULT           1

inherit F_CLEAN_UP;

int look_room(object me, object env, int brief);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string look_equiped(object me, object obj, string pro);
string look_all_inventory_of_room(object me, object env, int ret_str);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        object env;
        int result;
        string objid, where;

        if (! arg) result = look_room(me, environment(me), 0);
        else
        {
                if (sscanf(arg, "%s of %s", objid, where) == 2)
                {
                        if (where == "here")
                                obj = present(objid, environment(me));
                        else
                        if (where == "me")
                                obj = present(objid, me);
                        else
                        {
                                env = present(where, environment(me));
                                if (! objectp(env))
                                        return notify_fail("��Ҫ������Ķ�����\n");
                                obj = present(objid, env);
                                if (env->is_character() && env != me)
                                {
                                        if (! objectp(obj) ||
                                            ! obj->query("equipped") &&
                                            env->query_temp("handing") != obj)
                                                return notify_fail("���˺���û��©�������뿴�Ķ�������\n");
                                        message("vision", me->name() + "�������" + obj->name() +
                                                "����һ�������֪���ڴ�ʲô���⡣\n", env);
                                        message("vision", me->name() + "����" + env->name() + "��" +
                                                obj->name() + "����һ�������֪���ڴ�ʲô���⡣\n",
                                                environment(me), ({ me, env }));
                                }
                        }

                        if (! obj)
                                return notify_fail("����û������������\n");
                }        

                if( obj || (obj = present(arg, environment(me))) || (obj = present(arg, me)) )
                {
                        if( obj->is_character() && ! obj->is_corpse()) result = look_living(me, obj);
                        else result = look_item(me, obj);
                } else result = look_room_item(me, arg);
        }

        return result;
}

int look_room(object me, object env, int brief)
{
        int i;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                tell_object(me, "������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                return 1;
        }

        if( !brief )
        {
                str = sprintf( HIC + "%s" + NOR + "%s\n    %s%s" + NOR,
                        env->short(),
                        wizardp(me)? " - " + file_name(env): "",
                        env->long(),
                        env->query("outdoors") ? NATURE_D->outdoor_room_description() : "");
        } else
        {
                str = sprintf( HIC + "%s" + NOR + "%s\n" + NOR,
                        env->short(),
                        wizardp(me)? " - " + file_name(env): "");
        }

        if (mapp(exits = env->query("exits")))
	{
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if (sizeof(dirs) == 0)
                        str += "    ����û���κ����Եĳ�·��\n";
                else if (sizeof(dirs) == 1)
                        str += "    ����Ψһ�ĳ����� " + BOLD +
			       dirs[0] + NOR + "��\n";
                else
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
        }

        str += look_all_inventory_of_room(me, env, RETURN_RESULT);
        tell_object(me, str);
        
        return 1;
}

string desc_of_objects(object *obs)
{
        int i;

        string  str;
        mapping count;
        mapping unit;
        string  short_name;
        string  *dk;
        string league_name;

        if (obs && sizeof(obs) > 0)
        {
                str = "";
                count   = ([]);
                unit    = ([]);
    
                for (i = 0; i < sizeof(obs); i++)
                {
                        if (stringp(league_name = obs[i]->query("league/league_name")))
                        {
                               short_name = HIG + "��" + league_name + "��" + NOR + obs[i]->short();
                        }
                        else   short_name = obs[i]->short();
                        if (undefinedp(count[short_name]))
                        {
                                count += ([ short_name : 1 ]);
                                unit += ([ short_name : obs[i]->query("unit") ]);
                        }
                        else
                                count[short_name] += 1;
                }
    
                dk = sort_array(keys(count), 1);
                for (i = 0; i < sizeof(dk); i++)
                {
                        str += "  ";
                        if (count[dk[i]] > 1)
                                str += chinese_number(count[dk[i]]) + unit[dk[i]];
                        str += dk[i] + "\n";
                }
                return str;
        }

        return "";
}

string look_all_inventory_of_room(object me, object env, int ret_str)
{
        object *inv;
        object *obs;

        string  str;

        if (! env || ! me) return "";

        str = "";

        inv = all_inventory(env);
        if (! sizeof(inv)) return str;

        obs = filter_array(inv, (: $(me) != $1 && userp($1) && $(me)->visible($1) :));
        str += desc_of_objects(obs);

        obs = filter_array(inv, (: $(me) != $1 && ! userp($1) && $1->is_character() &&
                                   $(me)->visible($1) :));
        str += desc_of_objects(obs);

        obs = filter_array(inv, (: ! $1->is_character() :), me);
        str += desc_of_objects(obs);

        if (! ret_str)
                tell_object(me, str);

        return str;
}

int look_item(object me, object obj)
{
        object hob;
        mixed *inv;
        mapping count;
        mapping equiped;
        mapping unit;
        string short_name;

        string str;
        string *dk;
        int i;

        count   = ([]);
        unit    = ([]);
        equiped = ([]);

        str = obj->long();
        while (mapp(obj->query_temp("daub")))
        {
                if (! obj->query_temp("daub/poison/remain"))
                        // no poison remain now
                        break;

                if (obj->query_temp("daub/poison/id") == me->query("id"))
                {
                        str += HIG "�㷢�������滹�������Ƶ�" +
                               obj->query_temp("daub/poison/name") +
                               HIG "�ء�\n" NOR;
                        break;
                }

                if (obj->query_temp("daub/who_id") == me->query("id"))
                {
                        str += HIG "�����滹�������ֲ��µ�" +
                               obj->query_temp("daub/poison/name") +
                               HIG "�ء�\n" NOR;
                        break;
                }

                if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
                        // nothing was worked out
                        break;

                str += HIG "��Ȼ���㷢�������ƺ�����һЩ����ӫ��";
                if (me->query_skill("poison", 1) >= 120)
                {
                        str += "��������" + obj->query_temp("daub/poison/name");
                }

                str += "��\n" NOR;
                break;
        }

        if (obj->query("consistence"))
                str += sprintf("�;öȣ�" WHT "%d%%\n" NOR, obj->query("consistence"));

        inv = all_inventory(obj);
        if (! sizeof(inv))
        {
                message("vision", str, me);
                return 1;
        }

        if (obj->is_corpse())
        {
                if (objectp(hob = obj->query_temp("handing")))
                {
                        if (hob->query_amount())
                                str += "���л���������һ" + hob->query("base_unit") +
                                       hob->name() + "��";
                        else
                                str += "���л���������һ" + hob->query("unit") +
                                       hob->name() + "��";
                        inv -= ({ hob });
                        if (! sizeof(inv))
                                str += "û��ʲô���������ˡ�\n";
                        else
                                str += "����������У�\n";
                } else
                        str += "����������У�\n";
        } else
                str += "�����У�\n";

        for (i = 0; i < sizeof(inv); i++)
        {
                short_name = inv[i]->short();
                if (undefinedp(count[short_name]))
                {
                        count += ([ short_name : 1 ]);
                        unit += ([ short_name : inv[i]->query("unit") ]);
                }
                else
                        count[short_name] += 1;

                if (inv[i]->query("equipped"))
                        equiped[short_name] = 1;
        }

        dk = keys(count);
        dk = sort_array(dk, 1);
        for (i = 0; i < sizeof(dk); i++)
        {
            if (equiped[dk[i]])
                str += HIC "  ��" NOR;
            else
                str += "    ";

            if (count[dk[i]] > 1)
                str += chinese_number(count[dk[i]]) + unit[dk[i]];
            str += dk[i] + "\n";
        }

        if (strlen(str) > 4096)
                me->start_more(str);
        else
                message("vision", str, me);
        return 1;
}

string look_equiped(object me, object obj, string pro)
{
        mixed *inv;
        string str;
        string subs;
        object hob;
        int i;
        int n;

        inv = all_inventory(obj);
        n = 0;

        str = "";
        subs = "";
        for (i = 0; i < sizeof(inv); i++)
        {
                switch (inv[i]->query("equipped"))
                {
                case "wielded":
                        n++;
                        subs = HIC "  ��" NOR + inv[i]->short() + "\n" + subs;
                        break;

                case "worn":
                        n++;
                        subs += HIC "  ��" NOR + inv[i]->short() + "\n";
                        break;

                default:
                        break;
                }
        }

        if (n)
                str += pro + "װ���ţ�\n" + subs;

        if (objectp(hob = obj->query_temp("handing")))
        {
                int mad;

                // dress nothing but handing a cloth !
                mad = (! objectp(obj->query_temp("armor/cloth")) &&
                       hob->query("armor_type") == "cloth");

                str = pro + "����" + (mad ? "ȴ" : "" ) + "����һ" +
                      (hob->query_amount() ? hob->query("base_unit")
                                           : hob->query("unit")) +
                      hob->name() +
                      (mad ? "�����ˣ�һ���Ƿ��ˣ�\n" : "��\n") + str;
        }

        if (playerp(obj) &&
            ! objectp(obj->query_temp("armor/cloth")))
        {
                str = pro + "����û�д��·�����\n" + str;
        }

        return str;
}

string description(object obj)
{
        if (playerp(obj))
        {
            int per;
            int age;
            per = obj->query_per();
            age = obj->query("age");
            if (obj->query("special_skill/youth")) age = 14;
            if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
            {
                    if (per >= 30) return "�������������ٷ磬�������Σ�����֮�䣬��ɷ���������������\n";
                    if (per >= 28) return "Ӣ������������������������棬��Ŀ���ʣ�ò���˰���\n";
                    if (per >= 24) return "��òӢ�����Ǳ����á��Ǹ����棬���˷��ס�\n";
                    if (per >= 18) return "��ٶ�����\n";
                    if (per >= 15) return "��òƽƽ��ûʲô�ÿ��ġ�\n";
                                   return "�����е�Բ�ס���ˡ�\n";
            } else
            {
                    if (per >= 30) return "��������֮ò����ɫ���������޾��ף������˼����ӣ�\n�������ƣ�����ʤѩ���绪��������֪�㵹�˶���Ӣ�ۺ��ܡ�\n";
                    if (per >= 28) return "�������ף����˶��ˡ��г�������֮�ݣ������߻�֮ò��\n������������Ŀ���飬������ɣ�����һЦ������������Ȼ�Ķ���\n";
                    if (per >= 26) return "������֬��üĿ�续���������֣��������ˡ��������Ҽ�������\n";
                    if (per >= 24) return "��ɫ����������κ죬�ۺ��ﲨ������Ͷ��֮�䣬ȷ��һ�����ϡ�\n";
                    if (per >= 21) return "���ʸ��ţ���Ŀ毺ã����㲻�Ͼ������ˣ�Ҳ���м�����ɫ��\n";
                    if (per >= 18) return "��òƽƽ�������ù�ȥ��\n";
                    if (per >= 15) return "��ò��������\n";
                                   return "���ú������е�����Ү��\n";
            }
        } else
        if (! obj->query("can_speak") && living(obj))
        {
                if (! obj->query_temp("owner"))
                        return "��һֻδ��ѱ�����������۹������ǽ��ĺ͵��⡣\n";
                else
                        return "��һֻ��" + obj->query_temp("owner_name") +
                               "ѱ����������һ������ѱ�����ӡ�\n";
        }

        return "";
}

int look_living(object me, object obj)
{
        int per;
        int spi;
        int age;
        int weight;
        string str, limb_status, pro, desc;
        mixed *inv;
        mapping my_fam, fam;
        int me_shen, obj_shen;
        string league_name;

        obj_shen = (int)obj->query("shen");
        per = obj->query_per();
        age = obj->query("age");
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if (playerp(obj) && ! (obj->query("born")))
        {
                tell_object(me, pro + "��û��Ͷ̥��ֻ��һ��Ԫ��ʲô��������Ү��\n");
                return 1;
        }

        me_shen = (int)me->query("shen");
        if (me != obj)
	{
                message("vision", me->name() + "�������㿴����֪���ڴ�"
			"ʲô���⡣\n", obj);
		message("vision", me->name() + "����" + obj->name() +
			"����һ�������֪���ڴ�ʲô���⡣\n", 
			environment(me), ({ me, obj }));
	}

        if (stringp(league_name = obj->query("league/league_name")))
        {
                  str = HIG + "��" + league_name + "��" + NOR + obj->long();
        }
        else str = obj->long();
        if (me != obj && objectp(obj->query_temp("is_riding")))
                str += sprintf("%s������%s�ϣ���ͷ�����㡣\n", pro, obj->query_temp("is_riding")->name());

        if (obj->is_character() &&
            obj->query("can_speak"))
        {
                // �������ɫ
                if (age >= 25 && obj->query("special_skill/youth"))
                        str += pro + "��������͵Ĵ�С������ֻ�ж�ʮ���ꡣ\n";
                else
                {
                        if (age >= 200)
                                str += pro + "��������ͺܴ��ˣ����Թ��ơ�\n";
                        else
                        if (age < 10)
                                str += pro + "������������ס�\n";
                        else
                                str += pro + "��������" + chinese_number(age / 10 * 10) +
                                       "���ꡣ\n";
                }
        }

        desc = description(obj);
        if (desc && desc != "")
                str += pro + desc;

       	// �������Ĵ����������
       	if (obj->is_character()
       	   && obj->query("tattoo"))
       	{
       		str += pro;

                // ����ɫ�����Ĵ������
       	        if (obj->query("tattoo/face_long"))
       	        {
       	                str += "�����ϴ���" +  obj->query("tattoo/face_long") + "��\n";

       	        	if (((obj->query("tattoo/chest_long")
       	           	   || obj->query("tattoo/back_long"))
       	           	   && ! objectp(obj->query_temp("armor/cloth")))
       	           	   || obj->query("tattoo/leftarm_long")
       	           	   || obj->query("tattoo/rightarm_long"))
                        	str += pro;
                }


                // �������ǰ��Ĵ�����������һ������������
       	        if ((obj->query("tattoo/chest_long")
       	           == obj->query("tattoo/back_long"))
       	           && obj->query("tattoo/chest_long")
       	           && obj->query("tattoo/back_long")
       	           && ! objectp(obj->query_temp("armor/cloth")))
       	        {
       	                str += "��¶�����ؿںͱ���������" +
       	                       obj->query("tattoo/chest_long") + "��\n";
       	        } else
       	        {
       	        	if (obj->query("tattoo/chest_long")
       	                   && ! objectp(obj->query_temp("armor/cloth")))
       	                	str += "��¶�����ؿ��ϴ���" +
       	                               obj->query("tattoo/chest_long") + "��\n";

       	        	if (obj->query("tattoo/back_long")
       	                   && ! objectp(obj->query_temp("armor/cloth")))
       	        	{
       	                	if (obj->query("tattoo/chest_long"))
       	                        	str += "��" + pro + "�ı���������" +
       	                                       obj->query("tattoo/back_long") + "��\n";
       	                	else
       	                        	str += "��¶���ı�������" +
       	                                       obj->query("tattoo/back_long") + "��\n";
       	        	}
       	        }

                // ��������ֱ۵Ĵ�����������һ������������
       	        if ((obj->query("tattoo/leftarm_long")
       	           == obj->query("tattoo/rightarm_long"))
       	           && obj->query("tattoo/leftarm_long")
       	           && obj->query("tattoo/rightarm_long"))
       	        {
       	                str += "��ʵ��˫���϶�����" +
       	                       obj->query("tattoo/leftarm_long") + "��\n";
       	        } else
                {
       	        	if (obj->query("tattoo/leftarm_long"))
       	                	str += "��ʵ������ϴ���" +
       	                               obj->query("tattoo/leftarm_long");

       	        	if (obj->query("tattoo/rightarm_long"))
       	        	{
       	                	if (obj->query("tattoo/leftarm_long"))
       	                        	str += "�����ұ������" +
       	                                       obj->query("tattoo/rightarm_long") + "��\n";
       	                	else
       	                        	str += "��ʵ���ұ��ϴ���" +
       	                                       obj->query("tattoo/rightarm_long") + "��\n";
       	        	} else
       	        	if (obj->query("tattoo/leftarm_long"))
       	                	str += "��\n";
       	        }
       	}

        //check about wife and husband
        if (obj->query("id")== me->query("couple/id"))
        {
                // ���޹�ϵ
                if ((string)me->query("gender") == "Ů��")
                        str += sprintf("%s������ķ����\n", pro);
                else
                        str += sprintf("%s����������ӡ�\n", pro);
        } else
        if (obj->is_brother(me))
        {
                // �ֵ�
                if (obj->query("gender") == "Ů��")
                {
                        if (obj->query("mud_age") > me->query("mud_age"))
                                str += sprintf("%s�������㡣\n", pro);
                        else
                                str += sprintf("%s����Ľ������ӡ�\n", pro);
                } else
                {
                        if (obj->query("mud_age") > me->query("mud_age"))
                                str += sprintf("%s����Ľ����ֳ���\n", pro);
                        else
                                str += sprintf("%s�������ܡ�\n", pro);
                }
        } else
        if (obj != me && obj->query("league") &&
            obj->query("league/league_name") == me->query("league/league_name"))
        {
                str += sprintf("%s�������%s��ͬ����ʿ��\n", pro,
                               obj->query("league/league_name"));
        }

        // If we both has family, check if we have any relations.
        if (obj != me &&
            mapp(fam = obj->query("family")) &&
            mapp(my_fam = me->query("family")) &&
            fam["family_name"] == my_fam["family_name"])
        {

                if (fam["generation"] == my_fam["generation"])
                {

                        if ((string)obj->query("gender") == "����" ||
                                (string)obj->query("gender") == "����")
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else
                if (fam["generation"] < my_fam["generation"])
                {
                        if (my_fam["master_id"] == obj->query("id"))
                                str += pro + "�����ʦ����\n";
                        else
                        if (my_fam["generation"] - fam["generation"] > 1)
                                str += pro + "�����ͬ�ų�����\n";
                        else
                        if (fam["enter_time"] < my_fam["enter_time"])
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else
                {
                        if (fam["generation"] - my_fam["generation"] > 1)
                                str += pro + "�����ͬ������\n";
                        else
                        if (fam["master_id"] == me->query("id"))
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }

        if (obj->is_chatter())
        {
                message("vision", str, me);
                return 1;
        }

        if (stringp(obj->query_temp("eff_status_msg")))
        {
                str += obj->query_temp("eff_status_msg") + "\n";
        } else
        if (obj->query("max_qi"))
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

        if (obj->query_temp("daub/poison/remain") &&
            (me == obj || random((int)me->query_skill("poison", 1)) > 80))
        {
                str += pro + HIG "��������" + (me == obj ? "" : "�ƺ�") +
                       "����" + (me == obj ? obj->query_temp("daub/poison/name") : "��") +
                       NOR "��\n";
        }

        str += look_equiped(me, obj, pro);
        message("vision", str, me);

        if (obj != me
           && living(obj)
           && ! me->is_brother(obj)
           && ! obj->query_condition("die_guard")
           && ! me->query_condition("die_guard")
           && me->query("couple/id") != obj->query("id")
           && (((me_shen < 0) && (obj_shen > 0))
           || ((me_shen > 0) && (obj_shen < 0)))
           && (((me_shen - obj_shen) > ((int)obj->query("max_neili") * 20))
           || ((obj_shen - me_shen) > ((int)obj->query("max_neili") * 20))))
        {
                tell_object(me, obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                if (obj->query("age") > 15 && me->query("age") > 15)
                   if (! wizardp(obj) && ! wizardp(me))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }
        return 1;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if (! objectp(env = environment(me)))
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
        if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg]))
	{
                if (stringp(item[arg]))
                        tell_object(me, item[arg]);
                else
		if(functionp(item[arg]))
                        tell_object(me, (string)(*item[arg])(me));

                return 1;
        }
        if (mapp(exits = env->query("exits")) && ! undefinedp(exits[arg]))
	{
                if (objectp(env = find_object(exits[arg])))
                        look_room(me, env, 0);
                else
		{
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]), 0);
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲô��\n");
}

int help(object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ������
��lookָ������в��������Ȳ쿴�����Ƿ��и���Ʒ�����û�����
�������ڵĻ������Ƿ��и���Ʒ�������������ϵ���Ʒ��������
�Ļ�����ID��ͬ����Ʒ�������ָ��look ??? of me/here ��ָ����
��Ҫ�쿴�Լ����ϵ���Ʒ���Ǹ��������е���Ʒ��ͬʱ�����ʹ����
�� look ??? of <id> ���Կ����˵�װ����������������Ʒ��

HELP
);
        return 1;
}

