// jinshe1.c 

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>; 

void setup()
{}

void create()
{
        set_name(YEL"��������ܸ��" NOR "�ϲ�", ({ "jinshe book1","book1", }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
                set("long",
        "����һ���ñ�ֽд�ɵ��顣���飺��������ܸ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n", );
		set("skill", ([
			"name"        : "jinshe-jian",
			"exp_required":	800000,
			"jing_cost"   :	55,
			"difficulty"  :	98,
			"max_skill"   : 10,
		]));
        }
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;

        string skill, book, msg;
        int lv;

        if (! arg)
        {
                write("�ж�������ָܸ���ʽ��read <����> from <������ܸ>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", skill, book) != 2)
        {
                write("�ж�������ָܸ���ʽ��read <����> from <������ܸ>\n");
                return 1;
        }

        if (me->is_busy())
        {
                write("��������æ���ء�\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (where->query("no_fight")
           && me->query("doing") != "scheme")
        {
                write("���޷������ﾲ�������ж�������ܸ��\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if (! id(book))
        {
                write("����û���Ȿ�顣\n");
                return 1;
        }

        if (skill != "�������" && skill != "��Ӱ���"
           && skill != "��������")
        {
                write("������ܸ�ϲ�û�м���������о������ݡ�\n" NOR);
                return 1;
        }

        if ((int)me->query("combat_exp") < 800000)
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if (skill == "�������")
        {
           if (me->query("can_perform/jinshe-jian/kun"))
           {
                write("�㲻���Ѿ�������\n");
                return 1;
           }
           if (me->query_skill("jinshe-jian", 1) < 140)
           {
                write("����߽��������������޷��ж��˾��У�\n");
                return 1;
           }

           if (random (5) != 1)
           {
                write("���о��˰��죬��Ȼ�޷�����������ǡ��ڻ��ͨ��\n");
                me->start_busy(15); 
                me->set("jing", 1);
                return 1;
           }
           msg = HIG "$N" HIG "������ܸ����ϸ�о����������ص���ѧ�����Ǽ��������"
                     "����\n" NOR;

           msg += HIG "$N" HIG "��̾һ�����п���ǧ��\n" NOR; 
           message_vision(msg, me); 

           if (me->can_improve_skill("sword"))
                   me->improve_skill("sword", 1500000);
           if (me->can_improve_skill("jinshe-jian"))
                   me->improve_skill("jinshe-jian", 1500000);
           if (me->can_improve_skill("martial-cognize"))
                   me->improve_skill("martial-cognize", 1500000);

           write(HIW "��ѧ���ˡ�" HIG "�������" HIW "����\n" NOR);
           me->set("can_perform/jinshe-jian/kun", 1);
           
           return 1;
        }
    
        else 
       
        if (skill == "��Ӱ���")
        {
           if (me->query("can_perform/jinshe-jian/wan"))
           {
                write("�㲻���Ѿ�������\n");
                return 1;
           }
           if (me->query_skill("jinshe-jian", 1) < 180)
           {
                write("����߽��������������޷��ж��˾��У�\n");
                return 1;
           }

           if (random (8) != 1)
           {
                write("���о��˰��죬��Ȼ�޷�������Ӱ������ڻ��ͨ��\n");
                me->start_busy(15);
                me->set("jing", 1);
                return 1;
           }
           msg = HIG "$N" HIG "������ܸ����ϸ�о����������ص���ѧ�����Ǽ��������"
                     "����\n" NOR;
           msg += HIG "$N" HIG "��̾һ�����п���ǧ��\n" NOR; 

           message_vision(msg, me); 

           if (me->can_improve_skill("sword"))
                   me->improve_skill("sword", 1500000);
           if (me->can_improve_skill("jinshe-jian"))
                   me->improve_skill("jinshe-jian", 1500000);
           if (me->can_improve_skill("martial-cognize"))
                   me->improve_skill("martial-cognize", 1500000);

           write(HIW "��ѧ���ˡ�" HIG "��Ӱ���" HIW "����\n" NOR);
           me->set("can_perform/jinshe-jian/wan", 1);

           return 1;
        }
 
        else 

        if (skill == "��������")
        {
           if (me->query("can_perform/jinshe-jian/shi"))
           {
                write("�㲻���Ѿ�������\n");
                return 1;
           }
           if (me->query_skill("jinshe-jian", 1) < 200)
           {
                write("����߽��������������޷��ж��˾��У�\n");
                return 1;
           }

           if (random (10) != 1)
           {
                write("���о��˰��죬��Ȼ�޷��������ݺ᡹�ڻ��ͨ��\n");
                me->start_busy(15);
                me->set("jing", 1);
                return 1;
           }
           msg = HIG "$N" HIG "�������ף���ϸ�о����������ص���ѧ�����Ǽ��������"
                     "����\n" NOR;
           msg += HIG "$N" HIG "��̾һ�����п���ǧ��\n" NOR; 
           message_sort(msg, me); 

           if (me->can_improve_skill("sword"))
                   me->improve_skill("sword", 1500000);
           if (me->can_improve_skill("jinshe-jian"))
                   me->improve_skill("jinshe-jian", 1500000);
           if (me->can_improve_skill("martial-cognize"))
                   me->improve_skill("martial-cognize", 1500000);

           write(HIW "��ѧ���ˡ�" HIG "��������" HIW "����\n" NOR);
           me->set("can_perform/jinshe-jian/shi", 1);
           
           return 1;
        }
}