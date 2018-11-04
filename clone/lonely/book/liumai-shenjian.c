#include <ansi.h>; 
inherit ITEM;

void create()
{
        set_name(HIW "���������ס�" NOR, ({ "liumai jianpu", "liumai", "jianpu"}));
        set_weight(500);
        if (clonep())
               destruct(this_object());
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long", HIW "\n����һ���ñ�ֽд�ɵ��飬��Ƥ��д�С�������"
                            "���ס���\n�֡���������Ŷ���(read)����\n\n" NOR, );
        }
}

void init()
{
        add_action("do_du", "read");
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
                write("�ж���������ָ���ʽ��read <����> from <��������>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", skill, book) != 2)
        {
                write("�ж���������ָ���ʽ��read <����> from <��������>\n");
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
                write("���޷������ﾲ�������ж��������ס�\n");
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

        if (skill != "shaochong-sword" && skill != "�ٳ彣"
           && skill != "guanchong-sword" && skill != "�س彣"
           && skill != "shaoze-sword" && skill != "����"
           && skill != "zhongchong-sword" && skill != "�г彣"
           && skill != "shangyang-sword" && skill != "������"
           && skill != "shaoshang-sword" && skill != "���̽�"
           && skill != "���ν���" && skill != "��������"
           && skill != "���ݺ�")
        {
                write("���������ϲ�û�м���������о������ݡ�\n" NOR);
                return 1;
        }

        if ((int)me->query("combat_exp") < 1000000)
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if ((int)me->query("jing") < 100
           || (int)me->query("qi") < 100
           || (int)me->query("neili") < 200)
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        if (skill == "���ν���")
        {
           if (me->query("can_perform/liumai-shenjian/qi"))
           {
                write("�㲻���Ѿ�������\n");
                return 1;
           }
           if (me->query_skill("liumai-shenjian", 1) < 185)
           {
                write("�������񽣲����������޷��ж��˾��У�\n");
                return 1;
           }

           if (random (10) != 1)
           {
                write("���о��˰��죬��Ȼ�޷��������ν������ڻ��ͨ��\n");
                me->start_busy(15); 
                me->set("jing", 1);
                return 1;
           }
           msg = HIG "$N" HIG "�������ף���ϸ�о����������ص���ѧ�����Ǽ��������"
                     "����\n" NOR;
           msg += HIG "$N" HIG "��ָһ����һ���������׵����ν���ֱ����ʡ�\n" NOR;
           msg += HIG "$N" HIG "��̾һ�����п���ǧ���������ջص��\n" NOR; 
           message_vision(msg, me); 

           if (me->can_improve_skill("finger"))
                   me->improve_skill("finger", 1500000);
           if (me->can_improve_skill("liumai-shenjian"))
                   me->improve_skill("liumai-shenjian", 1500000);
           if (me->can_improve_skill("martial-cognize"))
                   me->improve_skill("martial-cognize", 1500000);

           write(HIW "��ѧ���ˡ�" HIG "���ν���" HIW "����\n" NOR);
           me->set("can_perform/liumai-shenjian/qi", 1);
           destruct(this_object());
           return 1;
        }
    
        else 
       
        if (skill == "��������")
        {
           if (me->query("can_perform/liumai-shenjian/six"))
           {
                write("�㲻���Ѿ�������\n");
                return 1;
           }
           if (me->query_skill("liumai-shenjian", 1) < 220)
           {
                write("�������񽣲����������޷��ж��˾��У�\n");
                return 1;
           }

           if (random (18) != 1)
           {
                write("���о��˰��죬��Ȼ�޷����������������ڻ��ͨ��\n");
                me->start_busy(15);
                me->set("jing", 1);
                return 1;
           }
           msg = HIG "$N" HIG "�������ף���ϸ�о����������ص���ѧ�����Ǽ��������"
                     "����\n" NOR;
           msg += HIW "$N" HIW "̯��˫�֣���ָ��������ʱ��������ȣ���"
                  "�����ڣ���������������Ѩ��һ��������" HIW "��\n" NOR;
           msg += HIG "$N" HIG "��̾һ�����п���ǧ���������ջص��\n" NOR; 
           message_vision(msg, me); 

           if (me->can_improve_skill("finger"))
                   me->improve_skill("finger", 1500000);
           if (me->can_improve_skill("liumai-shenjian"))
                   me->improve_skill("liumai-shenjian", 1500000);
           if (me->can_improve_skill("martial-cognize"))
                   me->improve_skill("martial-cognize", 1500000);

           write(HIW "��ѧ���ˡ�" HIG "��������" HIW "����\n" NOR);
           me->set("can_perform/liumai-shenjian/six", 1);
           destruct(this_object());
           return 1;
        }
 
        else 

        if (skill == "���ݺ�")
        {
           if (me->query("can_perform/liumai-shenjian/zong"))
           {
                write("�㲻���Ѿ�������\n");
                return 1;
           }
           if (me->query_skill("liumai-shenjian", 1) < 240)
           {
                write("�������񽣲����������޷��ж��˾��У�\n");
                return 1;
           }
           if (me->query_skill("force", 1) < 340)
           {
                write("���ڹ���򲻹����޷��ж��˾��У�\n");
                return 1;
           }

           if (random (50) != 1)
           {
                write("���о��˰��죬��Ȼ�޷��������ݺ᡹�ڻ��ͨ��\n");
                me->start_busy(15);
                me->set("jing", 1);
                return 1;
           }
           msg = HIG "$N" HIG "�������ף���ϸ�о����������ص���ѧ�����Ǽ��������"
                     "����\n" NOR;
           msg += HIM "$N" HIM "һ����Х��ʮָ�׵����پ�����������ӿ����ͷ������"
                  "�˷������಻������ʱ�����籼�������޾������������Ȼ�������" HIM 
                  "��\n" NOR;
           msg += HIG "$N" HIG "��̾һ�����п���ǧ���������ջص��\n" NOR; 
           message_sort(msg, me); 

           if (me->can_improve_skill("finger"))
                   me->improve_skill("finger", 1500000);
           if (me->can_improve_skill("liumai-shenjian"))
                   me->improve_skill("liumai-shenjian", 1500000);
           if (me->can_improve_skill("martial-cognize"))
                   me->improve_skill("martial-cognize", 1500000);

           write(HIW "��ѧ���ˡ�" HIG "���ݺ�" HIW "����\n" NOR);
           me->set("can_perform/liumai-shenjian/zong", 1);
           destruct(this_object());
           return 1;
        }

        else 
       
        if (me->query_skill("liumai-shenjian", 1))
        {
             write("�㲻���Ѿ������������𣿻�ѧ���ʲô��\n");
             return 1;
        }

        else 
 
        if (skill == "shaochong-sword" || skill == "�ٳ彣")
		skill = "shaochong-sword";
        else

        if (skill == "shaoze-sword" || skill == "����")
		skill = "shaoze-sword";
        else

        if (skill == "shaoshang-sword" || skill == "���̽�")
		skill = "shaoshang-sword";
        else

        if (skill == "zhongchong-sword" || skill == "�г彣")
		skill = "zhongchong-sword";
        else

        if (skill == "guanchong-sword" || skill == "�س彣")
		skill = "guanchong-sword";
        else

        if (skill == "shangyang" || skill == "������")
		skill = "shangyang-sword";

        if (! SKILL_D(skill)->valid_learn(me))
               	return 0;

        if (! me->can_improve_skill(skill))
       	{
               	write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
               	return 1;
       	}

        lv = me->query_skill(skill, 1);

        if (lv >= 1)
	{
                write("���ж���һ��������Ƿ���������˵��ʵ�����ޡ�\n");
                return 1;
        }

        // �츳��ӱ�����ж��ٶ�
        if (me->query("special_skill/clever"))
                me->improve_skill(skill, me->query("int") + 5);
        else
                me->improve_skill(skill, me->query("int") + 1);

        me->receive_damage("qi", random(50) + 30);
        me->receive_damage("jing", random(50) + 30);
        me->add("neili", -lv);
        message("vision", me->name() + "��ר�ĵ��ж��������ס�\n",
                          environment(me), me);
        write("����ϸ�ж��������ף������ĵá�\n");
        destruct(this_object());
        return 1;
}
