#include <ansi.h>; 
inherit ITEM;

void create()
{
        set_name(WHT "�������澭���ϲ�" NOR, ({ "zhenjing shangce", "shangce", "zhenjing", "jing"}));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("material", "paper");
                set("no_sell", 1);
                set("long", WHT "\n����һ���ñ�ֽд�ɵ��飬��Ƥ��д�С������澭����\n"
                            "�����֡���Ƥ���ƣ������Ѿ�����ܾ��ˡ��澭�м���\n"
                            "�д��ħȭ���׽�͹Ǻ������귭�Ⱦ��������������\n"
                            "����(read)����\n\n" NOR, );
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

        string skill, book;
        int lv;

        if (! arg)
        {
                write("�ж������澭ָ���ʽ��read <����> from <�����澭>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", skill, book) != 2)
        {
                write("�ж������澭ָ���ʽ��read <����> from <�����澭>\n");
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
                write("���޷������ﾲ�������ж��澭��\n");
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

        if (skill != "yijin-duangu" && skill != "�׽�͹�"
           && skill != "shexing-lifan" && skill != "�����귭"
           && skill != "dafumo-quan" && skill != "���ħȭ")
        {
                write("�澭�ϲ�û�м���������о������ݡ�\n" NOR);
                return 1;
        }

        if (me->query_skill("sanscrit", 1) < 200)
        {
                write("�������ˮƽ̫�ͣ��޷������澭�������ص����ݡ�\n");        
                return 1;
        }

        if ((int)me->query("combat_exp") < 800000)
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

        if (skill == "yijin-duangu" || skill == "�׽�͹�")
		skill = "yijin-duangu";
        else

        if (skill == "shexing-lifan" || skill == "�����귭")
		skill = "shexing-lifan";
        else

        if (skill == "dafumo-quan" || skill == "���ħȭ")
		skill = "dafumo-quan";

        if (! SKILL_D(skill)->valid_learn(me))
               	return 0;

        if (! me->can_improve_skill(skill))
       	{
               	write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
               	return 1;
       	}

        lv = me->query_skill(skill, 1);

        if (lv >= 180)
	{
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˡ�\n");
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
        message("vision", me->name() + "��ר�ĵ��ж������澭��\n",
                          environment(me), me);
        write("����ϸ�ж������澭�������ĵá�\n");
        return 1;
}
