// league.c

#include <ansi.h>
#include <getconfig.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;

void create() { seteuid(getuid()); }

int sort_hatred(string id1, string id2, mapping hatred);
int sort_member(string id1, string id2);
int show_league_info(object me, string arg);
int show_league_member(object me, string arg);
int show_league_hatred(object me, string arg);
int dismiss_league(object me, string arg);
int add_member(object me, string arg);
int remove_member(object me, string arg);
int help(object me);
int league_kill(object me, string arg);

int main(object me, string arg)
{
        object *obs;
        string fname;
        string *args;
        string* member;
        object ob;
        int lvl, lvlold;
        mapping lvls = ([
              0 : "��",
              1 : "��",
              2 : "���",
              3 : "����",
              4 : "�����",
        ]);

        if (time() - me->query_temp("scan_time") < 3
           && ! wizardp(me) && arg != "check")
                return notify_fail("�ȵȣ�ϵͳ�����С���\n");

        if (! arg) arg = "info";
        args = explode(arg, " ");
        if (sizeof(args) > 1)
                arg = implode(args[1..<1], " ");
        else
                arg = 0;

        me->set_temp("scan_time", time());

        switch (args[0])
        {
        case "?":
                help(me);
                return 1;
        case "check":
                if (! stringp(fname = me->query("league/league_name")))
                        return 1;

                member = LEAGUE_D->query_members(me);

                if (! sizeof(member))
                {
                        // ͬ���Ѿ���ɢ
                        write(HIR "\n������ͨ�桿ͬ��ͨ�棺�����ߵ�ʱ��������ͬ���ѽ�ɢ��\n" NOR);
                        me->delete("league");
                        return 1;
                }
                // �ж��Ƿ����������ߵ�ʱ�򱻿�������ͬ���Ƿ��ѽ�ɢ
                if (member_array(me->query("id"), member) == -1)
                {
                        write(HIR "\n������ͨ�桿ͬ��ͨ�棺�����ߵ�ʱ��������ͬ���ѽ��㿪����\n" NOR);
                        LEAGUE_D->add_league_fame(me, -1 * me->query("weiwang"));
                        me->delete("league");

                        return 1;
                }

        case "info":
                // ��ʾͬ�˵���Ϣ
                return show_league_info(me, arg);

        case "member":
                if (! wizardp(me))
                        return notify_fail("��û���㹻Ȩ�ޣ�\n");

                return show_league_member(me, arg);

        case "dismiss":
                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query("id") != me->query("league/leader_id")
                    && ! wizardp(me))
                        return notify_fail("ֻ��ͬ�����������ʦ���ܽ�ɢͬ�ˣ�\n");

                return dismiss_league(me, arg);

        case "add":
                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query("id") != me->query("league/leader_id")
                    && ! me->query("league/grant"))
                        return notify_fail("��û���㹻Ȩ����ȡ��Ա��\n");

                return add_member(me, arg);

        case "join":
                if (! stringp(me->query_temp("wait_reply")))
                        return notify_fail("����û��ͬ����������룡\n");
                
                ob = find_living(me->query_temp("wait_reply"));
                if (! objectp(ob))
                {
                        me->delete_temp("wait_reply");
                        return notify_fail("�ղ�����������Ѿ����������ˣ�\n");
 
                }               

                me->set_temp("wait_join", 1);
                
                add_member(ob, me->query("id"));
                me->delete_temp("wait_reply");
                me->delete_temp("wait_join");

                return 1;

        case "grant":
                sscanf(arg, "%s %d", arg, lvl);

                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query("id") != me->query("league/leader_id"))
                        return notify_fail("ֻ��ͬ���������ʹ�ø�ָ�\n");

                if (! arg || 
                    ! intp(lvl) || 
                    lvl < 0 || 
                    lvl > 4)return notify_fail("ָ���ʽ�� league grant [id] [Ȩ�޵ȼ�(0��4)]��\n");
             
                ob = find_living(arg);

                if (! objectp(ob))
                        return notify_fail("����û�Ŀǰû�е�½��\n");
         
                if (me->query("league/league_name") != ob->query("league/league_name"))
                        return notify_fail("������ˣ���������ĳ�Ա��\n");

                if (me == ob)return notify_fail("���Ѿ��������ˣ�\n");

                // ���� lvl ����Ȩ��
                lvlold = ob->query("league/grant");
                ob->set("league/grant", lvl);

                CHANNEL_D->do_channel( me, "inter", HIY + me->name() + HIG
                           " �޸��� " HIY + ob->name() + HIG " ��Ȩ�ޡ�  "
                           HIG + lvls[lvlold] + "��" + lvls[lvl] + "\n" NOR);

                return 1;
                                
        case "kick":
                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query("id") != me->query("league/leader_id")
                    && me->query("league/grant") < 3)
                        return notify_fail("��û���㹻Ȩ�޿�����Ա��\n");

                if (me->query("id") == arg)
                        return notify_fail("�Լ����Լ���\n");

                if (me->query("league/leader_id") == arg)
                        return notify_fail("�ð��������䶼���ߣ�\n");
                                     
                return remove_member(me, arg);
                                
        case "top":
                return "/cmds/usr/top"->main(me, "league");

        case "hatred":
                // ��ʾͬ�˵ĳ���
                return show_league_hatred(me, arg);

        case "kill":
                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query("id") != me->query("league/leader_id")
                    && ! wizardp(me) &&  me->query("league/grant") < 2)
                        return notify_fail("��û���㹻Ȩ�޺���ͬ�˳�Ա����ս����\n");

                // ͬһ������ӵ���㹻Ȩ�޵ĺ������г�Ա��ĳ���󷢶�����
                return league_kill(me, arg);

        case "set":
                // ͬ���и��˵Ĳ�������
                if (! arg)
                {
                         write("��Ŀǰ�������£�\n");
                         write("no_kill    == " + me->query("league/set/no_kill") + "\n");
                         write("weiwang    == " + me->query("league/set/weiwang") + "��\n");

                         return 1; 
                }
                sscanf(arg, "%s %d", arg, lvl);
                if (arg != "no_kill" 
                    && arg != "weiwang"
                    && arg != "follow")
                {
                         write("ָ���ʽ��league set <����> <����> ��\n");
                         write("����    ��no_kill   <1>������ͬ��ս����\n");
                         write("                    <0>����ͬ��ս����\n");
                         write("          weiwang   <0��100> �������ʱ�ֽ������� weiwang % �ָ�ͬ�ˡ�\n\n");

                         return 1;

                }

                if (lvl <= 0)lvl = 0;
                if (lvl >= 100)lvl = 100;
                
                me->set("league/set/" + arg, lvl);
                write(HIG "OK��\n" NOR);
                
                return 1;
          
        case "title": 
                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query("id") != me->query("league/leader_id")
                    && ! wizardp(me) &&  me->query("league/grant") < 4)
                        return notify_fail("��û���㹻Ȩ�ޣ�\n");

                sscanf(arg, "%d %s", lvl, arg);

                if (!arg || lvl <=0 || lvl > 5)
                {
                        write("ָ���ʽ��league title <Ȩ�޵ȼ�(1-4)> <���> .\n");
                        return 1;
                }
                
                write("������ ...\n");
                return 1;                
        case "out":
                if (! stringp(fname = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�к��κ��˽�������ء�\n");

                if (me->query_temp("pending/out_league"))
                {
                        // ͬ�˵������½�
                        if (me->query("weiwang") < LEAGUE_D->query_league_fame(fname) / 10)
                                  LEAGUE_D->add_league_fame(fname, -1 * LEAGUE_D->query_league_fame(fname) / 10);
                        else 
                                  LEAGUE_D->add_league_fame(fname, -1 * me->query("weiwang"));
                        CHANNEL_D->do_channel(this_object(), "rumor",
                                "��˵" + me->name(1) + "(" + me->query("id") +
                                ")���޷��ˣ��Ѿ����롸 " HIG + fname + HIM" ����ȥ��");
                        me->delete_temp("pending/out_league");

                        // ������û���ͬ���е���Ϣ
                        UPDATE_D->clear_user_data(me->query("id"), "league");
                        return 1;
                }

                write("�������Ҫ���������Ľ���������������ή��" + fname + "��������\n"
                      YEL "�����ȷ���ˣ���������һ�� league out ���\n" NOR);
                me->set_temp("pending/out_league", 1);
                return 1;
        }

        write("��Ч�Ĳ�����\n");
        return 1;
}

// ������ҺͲ���ѡ��ͬ�˵�����
mixed select_league(object me, string arg)
{
        string fam;
        object ob;

        if (! wizardp(me))
                // only wizard can show every league's list
                fam = 0;
        else
        if (stringp(arg) && arg != "")
        {
                if (! arrayp(LEAGUE_D->query("member/" + fam)))
                        fam = 0;
                else
                        fam = arg;

                if (! stringp(fam) && objectp(ob = UPDATE_D->global_find_player(arg)))
                {
                        // û�� arg ���ͬ�ˣ��鿴�Ƿ��и����
                        fam = ob->query("league/league_name");
                        UPDATE_D->global_destruct_player(ob);
                        if (! stringp(fam))
                                return notify_fail("��������û�кͱ��˽��ͬ�ˡ�\n");
                }

                if (! stringp(fam))
                        return notify_fail("û�������ң����ܲ�����ص�ͬ�ˡ�\n");
        }

        if (! fam)
        {
                // select my league
                if (! stringp(fam = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�кͱ��˽�������ء�\n");
        }

        return fam;
}

// ��ʾͬ�˵ĳ���
int show_league_hatred(object me, string arg)
{
        mapping hatred;
        string fam;
        string *ids;
        mixed *data;
        string msg;
        string st;
        int count;
        int i;

        if (! stringp(fam = select_league(me, arg)))
                return 0;

        hatred = LEAGUE_D->query_league_hatred(fam);
        if (! mapp(hatred) || ! sizeof(hatred))
        {
                write(fam + "����û��ʲô���ˡ�\n");
                return 1;
        }

        ids = keys(hatred) - ({ 0 });
        ids = sort_array(ids, (: sort_hatred :), hatred);

        count = 0;
        msg = WHT "Ŀǰ" + fam + "�ڽ����ϵĳ�ж���\n" NOR
              HIY "��������������������������������\n" NOR;
        for (i = 0; i < sizeof(ids) && count < 30; i++)
        {
                data = hatred[ids[i]];
                if (! arrayp(data) || sizeof(data) < 2 ||
                    ! stringp(data[0]) || ! intp(data[1]))
                        continue;

                st = sprintf("%s(%s%s%s)", data[0], YEL, ids[i], NOR);
                msg += sprintf("%2d. %-34s  %s%-9d%s\n",
                               ++count, st, HIR, data[1], NOR);
        }

        msg += HIY "��������������������������������\n" NOR;
        if (i < sizeof(ids))
                msg += WHT "�����ϵĵ���̫�࣬���Ծ�����\n" NOR;
        else
                msg += WHT "Ŀǰһ����" + chinese_number(i) +
                       "�ˡ�\n" NOR;
        write(msg);
        return 1;
}

// ��ʾĳһ��ͬ���е���Ա
int show_league_member(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (! arg)
        {
                if (! stringp(arg = me->query("league/league_name")))
                        return notify_fail("�����ڻ�û�м����κ�һ��ͬ���ء�\n");
        }

	if (! arrayp(member = LEAGUE_D->query_members(arg)))
        {
                write("���ڽ�����û��(" + arg + ")����ֺš�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(arg + "�����˶�ϡ�䡣\n");

        if (! wizardp(me))
        {
                if (me->query("jing") < 50)
                        return notify_fail("�����ھ��񲻼ã��޷�������Щ��Ϣ��\n");

                if (me->is_busy())
                        return notify_fail("��������æ��û��ʱ�������Щ��Ϣ��\n");

                me->receive_damage("jing", 50);
                me->start_busy(3);
        }

        msg = "";
        n = 0;
        foreach (id in member)
        {
                user = UPDATE_D->global_find_player(id);
                if (! objectp(user))
                        continue;

                n++;
                msg += user->short(1) + "\n";
                UPDATE_D->global_destruct_player(user);
        }

        if (msg == "")
                return notify_fail(arg + "�����˶�ϡ�䡣\n");

        write(arg + "Ŀǰ������" + chinese_number(n) + "�ˣ�\n" + msg);
        return 1;
}

// ��ʾͬ���е���Ϣ
int show_league_info(object me, string arg)
{
        string fam;
        object  ob;
        string  msg;
        string pro;
        string *member;
        string  id;
        string leader_id, leader_name;
        int lvl;
        mapping lvls = ([
              0 : "��",
              1 : "��",
              2 : "���",
              3 : "����",
              4 : "�����",
        ]);

        if (! stringp(fam = select_league(me, arg)))
                return 0;

        if (fam == me->query("league/league_name"))
                pro = "��";
        else
                pro = fam;

	if (! arrayp(member = LEAGUE_D->query_members(fam)))
        {
                write("���ڽ�����û��(" + fam + ")����ֺš�\n");
                return 1;
        }

        if (sizeof(member) < 1)
                return notify_fail(pro + "����û��һ���ֵܡ�\n");

        leader_id = me->query("league/leader_id");
        leader_name = me->query("league/leader_name");

        msg = "\n������ ��" HIG + me->query("league/league_name") + NOR " ��"
              " �ľ�����Ϣ��" HIY "      ��ͬ�����䡿�� " + leader_name +
              "(" + leader_id + ")\n\n" NOR;

        member = sort_array(member, (: sort_member :));
        foreach (id in member)
        {
                msg += sprintf(WHT "%-10s  ", id);
                if (objectp(ob = find_player(id)))
                {
                        msg += sprintf(HIY "����   "
                                       NOR WHT "���飺" HIC "%-9d "
                                       NOR WHT "������" HIW "%-8d "
                                       NOR WHT "������" HIY "%-8d\t" NOR,
                                       ob->query("combat_exp"),
                                       ob->query("score"),
                                       ob->query("weiwang"));
                       if (lvl = ob->query("league/grant"))
                               msg += HIG + lvls[lvl] + "\n" NOR;
                       else    
                               msg += "\n";
                }
                else
                        msg += HIR "������\n" NOR;
        }

        msg += sprintf("\n����%s��һ����%sλ���ѣ��ڽ����Ͼ��� %s%d%s ��������\n",
                       fam, chinese_number(sizeof(member)),
                       HIY, LEAGUE_D->query_league_fame(fam), NOR);
        write(msg);

	return 1;
}

// ��ɢͬ��
int dismiss_league(object me, string arg)
{
        string *member;
        string id;
        object user;
        string msg;
        int n;

        if (! arg)
                return notify_fail("��Ҫ��ɢ�ĸ�ͬ�ˣ�\n");

	if (! arrayp(member = LEAGUE_D->query_members(arg)))
        {
                write("���ڽ�����û��(" + arg + ")����ֺš�\n");
                return 1;
        }

        if (arg != me->query("league/league_name")
            && ! wizardp(me))
        {
                write("��ֻ�ܽ�ɢ�����ڵ�ͬ�ˡ�\n");
                return 1;
        }

        write(HIR "��ǿ�н�ɢ��" + arg + "��\n" NOR);
        LEAGUE_D->dismiss_league(arg);
        return 1;
}

// ���һ����Ա
int add_member(object me, string arg)
{
        object member;
        string *members;
        string fam;

        if (! arg)
              return notify_fail("��Ҫ��ȡ˭Ϊ��Ա��\n");

        member = find_living(arg);
        fam = me->query("league/league_name");
        members = LEAGUE_D->query_members(fam);
        members = sort_array(members, (: sort_member :));

        if (! objectp(member))
        {
              write(arg + " ����˲��������ϣ��޷���ȡ�ó�Ա��\n");
              return 1;
        }

        if (! userp(member))
        {
              write("ֻ����ȡ���Ϊ��Ա��\n");
              return 1;
        }

        if (member->query("league/league_name"))
        {
              write("�������Ѿ�������һ��ͬ�ˣ�\n");
              return 1;
        }

        //ͬ�������ʮ����
        if (sizeof (members) >= 30)
        {
              write(HIR "ͬ�������ֻ������ʮ���ˣ�\n");
              return 1;
        }

        if (! member->query_temp("wait_join"))
        {
              write(HIG "��Ϣ�ѷ��������ȴ��Է���Ӧ��\n" NOR);
              tell_object(member, "\n" + HIY + me->name() + "(" + me->query("id") + ")��������� ��" 
                          HIG +  me->query("league/league_name") + HIY " ��"
                          "�������Ը�������룺 league join ��\n");

              member->set_temp("wait_reply", me->query("id"));

              return 1;

        }
       
        if (LEAGUE_D->add_member_into_league(me->query("league/league_name"), arg, me))
        {
              CHANNEL_D->do_channel( this_object(), "rumor", "��˵" + member->name() + "(" + 
                                     member->query("id") + ")������ ��" HIC + me->query("league/league_name") +
                                     HIM " ����\n" NOR);
              me->delete_temp("wait_reply");
              me->delete_temp("wait_join"); 
              LEAGUE_D->add_league_fame(me, member->query("weiwang"));
        }

        return 1;
       
}

// ����һ����Ա
int remove_member(object me, string arg)
{
        object ob;
        string* member;

        if (! arg)
              return notify_fail("��Ҫ�����ĸ���Ա��\n");
        
        if (arg == me->query("id"))
              return notify_fail("�����Ļ��㻹�����ɢͬ�����ˣ�\n");

        member = LEAGUE_D->query_members(me);

        if (member_array(arg, member) == -1)
              return notify_fail("������ͬ����û������ˣ�\n");
         
        LEAGUE_D->remove_member_from_league(me->query("league/league_name"), arg, 1);

        return 1;
      
}


// �����еĳ�޶�������
int sort_hatred(string id1, string id2, mapping hatred)
{
        mixed *d1, *d2;

        if (! arrayp(d1 = hatred[id1]) || sizeof(d1) < 2 || ! intp(d1[1]))
                return 1;

        if (! arrayp(d2 = hatred[id2]) || sizeof(d2) < 2 || ! intp(d2[1]))
                return -1;

        return d2[1] - d1[1];
}

// ��ͬ���е����н����Ա����
int sort_member(string id1, string id2)
{
        object ob1, ob2;

        ob1 = find_player(id1);
        ob2 = find_player(id2);
        if (! objectp(ob1) && ! objectp(ob2))
                return strcmp(id2, id1);

        if (objectp(ob1) && objectp(ob2))
                return ob2->query("combat_exp") - ob1->query("combat_exp");

        if (objectp(ob1))
                return -1;

        return 1;
}

// league kill 
int league_kill(object me, string arg)
{
        // league kill ����ʹ�õı�־
        int kill_flag;
        int want_kill_flag;
        
        object lob, obj, env;
        object *l;

        string leader, league_name;

        env = environment(me);

        if (env->query("no_fight"))
                return notify_fail("���ﲻ��ս����\n");
        
        league_name = me->query("league/league_name");

        if (! arg || ! objectp(obj = present(arg, env)))
                return notify_fail("���빥��˭��\n");

        if (! obj->is_character() || obj->is_corpse())
                return notify_fail("������ˣ��ǲ��ǻ��ˣ�\n");

        l = all_inventory(env);       

        foreach (lob in l)
        {
             if (me->query("league/leader_id") == lob->query("id"))
                      return notify_fail("���䶼��û����������ʲô����\n");

             if (! objectp(lob) ||
                 ! living(lob) ||
                 lob->query("doing") ||
                 lob->query("league/league_name") != league_name ||
                 lob->query("league/set/no_kill") ||
                 lob->query("id") == obj->query("id"))l -= ({ lob });
        }

        if (! sizeof(l) || sizeof(l) <= 1)
                return notify_fail("Ŀǰû������������٣�\n");

        if (obj == me)
                return notify_fail("ʲô����Ҫ��ɱҲ��Ҫ�б��˰���\n");

        if (league_name == obj->query("league/league_name"))
                return notify_fail("���빥�����Լ�ͬ�˳�Ա������û�˻�����Ļ���\n");


        message_vision("\n$Nһ���֣��ȵ����� ��" HIY + league_name + NOR"�� ���ֵ��Ǵ��һ��"
                       "���Ը�" + obj->name() + "����\n\n",
                       me, obj);

        switch (obj->accept_kill(me))
	{
	case 0:
                return (! objectp(obj));
	case -1:
                if (objectp(obj) &&
                    ! me->is_killing(obj->query("id")))
                {
                        // ��Ϊĳ��ԭ��ս��û�з���
		        return 1;
                }
	default:
	}

        // ս���Ѿ����������������е��˲���ս��
        message("vision", HIR "��ʹ��һ�����" + me->name(1) +
                          HIR "������ȥ��Χ��" + obj->name() +
                          "����һ���ҿ���\n" NOR, l, ({ me }));

        // �ж��Ƿ�������������ɱ���Է�
        if (userp(me) && userp(obj))
        {
                // �Է���ɱ�����˺����Ƕ����еĳ�Ա
                string *obj_wants;
                object *all_team;

                // ����ȡ�������Ա - ��Ϊ�������ε��ĳ�Ա
                // û�а����� l �����С�
                l = all_inventory(env);       
                foreach (lob in l)
                {
                       if (! objectp(lob) ||
                           ! living(lob) ||
                           lob->query("doing") ||
                           lob->query("league/league_name") != league_name ||
                           lob->query("id") == me->query("id"))l -= ({ obj });
              
                }

                all_team = l;

                all_team -= ({ 0 });
                obj_wants = obj->query_want() - ({ 0 });
                if (sizeof(obj_wants - l->query("id")) != sizeof(obj_wants))
                {
                        // �Է���ɱ�����Ƕ����е�ĳһЩ�ˣ�
                        // �����Ϊ�ǶԷ���ɱ�����ǣ�����
                        // ��֮
                        want_kill_flag = 0;
                } else
                {
                        me->want_kill(obj);
                        want_kill_flag = 1;
                }
        }

        // �ж϶Է��Ƿ��ɱ����
        if (living(obj) && ! userp(obj))
        {
                // �Է���ɱ������
                obj->kill_ob(me);
                kill_flag = 1;
        } else
        {
                // �Է�����ɱ�����ǣ�ֻ�ǹ�������
                obj->fight_ob(me);
                kill_flag = 0;
        }

        // �������������е���
        foreach (lob in l)
        {
                // ɱ�˷���Ͷӳ�����һ�£�����Է�
                // �������������е�ĳһ���ˣ�������
                // �ǶԷ�����
                if (want_kill_flag)
                        lob->want_kill(obj);

                lob->kill_ob(obj);

                // ���ö��ֵĹ���״̬�Ͷӳ�����һ��
                if (kill_flag)
                        obj->kill_ob(lob);
                else
                        obj->fight_ob(lob);
        }

        return 1;

}

int help(object me)
{
   	write(@HELP

ָ���ʽ: league info [���] | hatred [���] | member [ͬ������] | top
          
�鿴Ŀǰ������ͬ�˵ĸ�����Ϣ�����У�

info     ���鿴ͬ���е������Ա״̬��������
hatred   ���鿴ͬ�˵ĳ�޶���
member   ���鿴ĳ��ͬ�˵ĳ�Ա������ʦ���ã���
top      ���鿴����ͬ�˵�����������

add      ������һ��ͬ�˳�Ա��
kick     ������һ��ͬ�˳�Ա��
dismiss  ��ǿ�н�ɢ��ǰͬ�ˡ�
��       ���鿴�й�ͬ��ָ�����Ϣ��
kill     ������ͬһ����ĳ�Ա����ĳһĿ�꣨�ƻ��е���ҳ��⣩��
grant    ���޸ĳ�ԱȨ�ޡ�
           ��ʽ�� league grant [id] [0-4]
                  0 ��ȡ���ó�Ա����Ȩ�ޡ�
                  1 ��league add [] Ȩ�ޡ� 
                  2 ��league kill [] Ȩ�ޡ� 
                  3 ��league kick [] Ȩ�ޡ�
                  4 ������չ��
            ע��Ȩ���Ǵ�0��4���������縳����ĳ�ˣ�league grant who 3����Ȩ�ޣ�
                ��ô���˲�����kick��Ȩ�ޣ����ҵ���kick���µ�Ȩ�ޣ�add, kill��
                ����ӵ�С�

set      �� �������á�
            ��ʽ��league set <����>  <����> ��
                  league set          ����ʾ��ǰ���á�
                  league set no_kill  ��������ͬ��ս��������Ӧ�κ��˺���league kill����
                  league set weiwang  ��ÿ�λ�ȡ������ʱ�򽫷ָ�ͬ�� weiwang������������             

��ʦ���Բ鿴����ͬ�˵���Ϣ��ֻ��Ҫ������������ͬ�˵����ֻ�
��ͬ���е���ҡ�������ʦ���߸�ͬ���������ʹ�� league dismiss 
����ǿ�н�ɢһ��ͬ�ˡ�

see also: team (����ͬ��)
HELP );
   	return 1;
}
