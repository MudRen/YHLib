#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIR "����" NOR, ({ "jia sha", "jia", "sha", "cloth"}));
        set_weight(1500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIR "һ�����ɫ�Ĵֲ����ģ�������������д����С�֡�\n" NOR);
                set("value", 1000);
                set("no_sell", 1);
                set("material", "cloth");
                set("armor_prop/armor", 25);
                set("wear_msg", HIR "$N" HIR "չ��һ�����ɫ�������������ϡ�\n" NOR);
                set("remove_msg", HIR "$N" HIR "�����Ĵ����������������۵���СС��һ�š�\n" NOR);
        }
        setup();
        move("/d/fuzhou/liang");
}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
        add_action("do_yanjiu", "yanjiu");
        add_action("do_yanjiu", "research");
}

int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        mapping skill;
        int plvl, con, improve;
        int neili_lost;

        if (! arg || ! id(arg))
                return 0;

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

        if (where->query("no_fight") && me->query("doing") != "scheme")
        {
                write("���޷������ﾲ�������ж����䡣\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if (me->query("character") == "��������" ||
            me->query("character") == "������")
        {
                write("�����а��������а���������𼺣����������á�\n");
                return 1;
        }

        if (me->query("gender") == "Ů��")
        {
                write("�Թ�����û��˵��Ů�˿�����ϰ�������䡣\n");
                return 1;
        }

        if (me->query("gender") == "����")
        {
                me->receive_wound("qi", 50);
                write(HIR "\n������������а��������ʱֻ����Ϣ��Ȼ���ң���"
                      "������\n" NOR);
                return 1;
        }

        if (me->query("int") < 34)
        {
                write("������ʲ��㣬�޷�����а���������⡣\n");
                return 1;
        }

        if (me->query("dex") < 32)
        {
                write("������������������������а������\n");
                return 1;
        }

        if (me->query_skill("sword", 1) < 100)
        {
                write("��Ļ�����������̫ǳ���޷�����а������\n");
                return 1;
        }

        if (me->query_skill("dodge", 1) < 100)
        {
                write("��Ļ����Ṧ����̫ǳ���޷�����а������\n");
                return 1;
        }

        if (me->query_skill("parry", 1) < 100)
        {
                write("��Ļ�����������̫ǳ���޷�����а������\n");
                return 1;
        }

        if (me->query_skill("pixie-jian", 1) >= 180)
        {
                write("����������صĶ���������˵�Ѿ�̫��ǳ���ˡ�\n");
                return 1;
        }

        if ((int)me->query("combat_exp") < 300000)
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if ((int)me->query("max_neili") < 500)
        {
                write("�������̫��޷������˵��񹦡�\n");
                return 1;
        }

        switch (random(3))
        {
        case 0:
                message("vision", CYN "ֻ��" + me->name() + CYN "͵͵"
                        "�����������ж�һ�����ġ�\n" NOR,
                        environment(me), me);
                break;
        case 1:
                message("vision", CYN + me->name() + CYN "����һ������"
                        "ɧ��Ū�ˣ�������ģ��Ů�ˡ�\n" NOR,
                        environment(me), me);
                break;
        case 2:
                message("vision", CYN + me->name() + CYN "�߶����ı߰�"
                        "����Ť��Ťȥ����Ϊ���졣\n" NOR,
                        environment(me), me);
                break;
        }

        if ((int)me->query("jing") < 60)
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        plvl = me->query_skill("pixie-jian", 1);
        if (plvl > 170) neili_lost = 120; else
        if (plvl > 150) neili_lost = 100; else
        if (plvl > 130) neili_lost = 90; else
        if (plvl > 110) neili_lost = 80; else
        if (plvl > 100) neili_lost = 70; else
        if (plvl > 90)  neili_lost = 60; else
        if (plvl > 80)  neili_lost = 50; else
        if (plvl > 70)  neili_lost = 40; else
        if (plvl > 60)  neili_lost = 30; else
        if (plvl > 50)  neili_lost = 20; else
                        neili_lost = 10;

        con = me->query_con();

        if ((int)me->query("neili") < neili_lost)
        {
                write("�������������޷�������ô������书��\n");
                return 1;
        }

        if (! me->can_improve_skill("pixie-jian", 1))
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if ((plvl > 10) && (con / 2 + random(con) < 50) && random(100) == 1)
        {
                tell_object(me, HIR "�������ű�����ʾ��ת��Ϣ��ͻȻֻ����Ϣ������"
                                "�ϣ���֫�������Ļ���\n�٣��Һ�һ�������˹�ȥ��\n" NOR);

                message("vision", HIR + me->name() + "ͻȻ�Һ�һ�������˹�ȥ��\n"
                                  NOR, environment(me), ({ me }));

                if ((int)me->query("max_neili") > 10)
                {
                        me->add("max_neili", -10 - random(10));
                }
                me->unconcious();
                return 1;
        }

        me->receive_damage("jing", random(30) + 30);
        me->add("neili", -neili_lost);

        // �츳��ӱ�����ж��ٶ�
        if (me->query("special_skill/clever"))
                me->improve_skill("pixie-jian", me->query("int") + 5);
        else
                me->improve_skill("pixie-jian", me->query("int") + 1);

        me->start_busy(random(1) + 1);
        write(HIR "����ϸ�ж������ϼ��ص��񹦣������ĵá�\n" NOR);
        return 1;
}

int do_yanjiu(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        string pfm, jiasha;
        int lv;

        if (! arg)
        {
                write("�о���������ָ���ʽ��research|yanjiu <����> from <��������>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", pfm, jiasha) != 2)
        {
                write("�о���������ָ���ʽ��research|yanjiu <����> from <��������>\n");
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

        if (where->query("no_fight") && me->query("doing") != "scheme")
        {
                write("���޷������ﾲ�������ж����䡣\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if (! id(jiasha))
        {
                write("��Ҫ�о�ʲô��\n");
                return 1;
        }

        if (pfm != "gui" && pfm != "duo" && pfm != "pi" && pfm != "po")
        {
                write("�����ϲ�û�м��������о��ľ��С�\n");
                return 1;
        }

        if ((int)me->query("combat_exp") < 300000)
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if ((int)me->query("jing") < 100)
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        if (me->query("potential") < me->query("learned_points") + 10) 
        {
                write("���Ǳ�ܲ����ˣ��о�����ʲô��\n");
                return 1;
        }

        // ��а�������ж�Ŀ��
        if (pfm == "duo")
	{
	        if ((int)me->query("can_perform/pixie-jian/duo"))
	        {
        	        write("���Ѿ�ѧ�������У����о�Ҳû�á�\n");
                	return 1;
	        }

	        if (! (int)me->query_skill("pixie-jian"))
	        {
        	        write("���о��˰��죬�������������صľ���������޹�ϵ��\n");
                	return 1;
	        }

        	if ((int)me->query_skill("pixie-jian", 1) < 80)
	        {
        	        write("�㷢�������ϼ��صľ��й�����£�һʱ�������ס�\n");
                	return 1;
	        }

        	if (random(20) < 18)
        	{
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
                	tell_object(me, HIY "��Ա�а�������˸������⣬�������һ"
                                       "�����о���\n" NOR);
        	} else
        	{ 
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
	                tell_object(me, HIY "�������ã���Ȼ����˫Ŀһ��������������"
                                        "�����������صı�а������������Ŀ�񽣡��İ�"
                                        "�أ�\n" NOR + HIC "��ѧ���ˡ���Ŀ�񽣡���\n" NOR);

	                if (me->can_improve_skill("sword"))
        	                me->improve_skill("sword", 1500000);
	                if (me->can_improve_skill("dodge"))
        	                me->improve_skill("dodge", 1500000);
	                if (me->can_improve_skill("parry"))
        	                me->improve_skill("parry", 1500000);
                	if (me->can_improve_skill("pixie-jian"))
                        	me->improve_skill("pixie-jian", 1500000);
              		me->improve_skill("martial-cognize", 1500000);
                	me->set("can_perform/pixie-jian/duo", 1);
        	}
               	me->receive_damage("jing", 80);
               	me->add("learned_points", 10);
               	me->start_busy(2);
                return 1;
	}

        // ��а�������й�����
        if (pfm == "gui")
	{
	        if ((int)me->query("can_perform/pixie-jian/gui"))
	        {
        	        write("���Ѿ�ѧ�������У����о�Ҳû�á�\n");
                	return 1;
	        }

	        if (! (int)me->query_skill("pixie-jian"))
	        {
        	        write("���о��˰��죬�������������صľ���������޹�ϵ��\n");
                	return 1;
	        }

        	if ((int)me->query_skill("pixie-jian", 1) < 100)
	        {
        	        write("�㷢�������ϼ��صľ��й�����£�һʱ�������ס�\n");
                	return 1;
	        }

        	if (random(30) < 28)
        	{
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
                	tell_object(me, HIY "��Ա�а�������˸������⣬�������һ"
                                       "�����о���\n" NOR);
        	} else
        	{ 
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
	                tell_object(me, HIY "�������ã���Ȼ����˫Ŀһ��������������"
                                        "�����������صı�а�������������������İ�"
                                        "�أ�\n" NOR + HIC "��ѧ���ˡ�����������\n" NOR);

	                if (me->can_improve_skill("sword"))
        	                me->improve_skill("sword", 1500000);
	                if (me->can_improve_skill("dodge"))
        	                me->improve_skill("dodge", 1500000);
	                if (me->can_improve_skill("parry"))
        	                me->improve_skill("parry", 1500000);
                	if (me->can_improve_skill("pixie-jian"))
                        	me->improve_skill("pixie-jian", 1500000);
              		me->improve_skill("martial-cognize", 1500000);
                	me->set("can_perform/pixie-jian/gui", 1);
        	}
               	me->receive_damage("jing", 80);
               	me->add("learned_points", 10);
               	me->start_busy(2);
                return 1;
	}

        // ��а��������Ⱥа����
        if (pfm == "pi")
	{
	        if ((int)me->query("can_perform/pixie-jian/pi"))
	        {
        	        write("���Ѿ�ѧ�������У����о�Ҳû�á�\n");
                	return 1;
	        }

	        if (! (int)me->query_skill("pixie-jian"))
	        {
        	        write("���о��˰��죬�������������صľ���������޹�ϵ��\n");
                	return 1;
	        }

        	if ((int)me->query_skill("pixie-jian", 1) < 120)
	        {
        	        write("�㷢�������ϼ��صľ��й�����£�һʱ�������ס�\n");
                	return 1;
	        }

        	if (random(40) < 38)
        	{
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
                	tell_object(me, HIY "��Ա�а�������˸������⣬�������һ"
                                       "�����о���\n" NOR);
        	} else
        	{ 
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
	                tell_object(me, HIY "�������ã���Ȼ����˫Ŀһ��������������"
                                        "�����������صı�а����������Ⱥа���ס��İ�"
                                        "�أ�\n" NOR + HIC "��ѧ���ˡ�Ⱥа���ס���\n" NOR);

	                if (me->can_improve_skill("sword"))
        	                me->improve_skill("sword", 1500000);
	                if (me->can_improve_skill("dodge"))
        	                me->improve_skill("dodge", 1500000);
	                if (me->can_improve_skill("parry"))
        	                me->improve_skill("parry", 1500000);
                	if (me->can_improve_skill("pixie-jian"))
                        	me->improve_skill("pixie-jian", 1500000);
              		me->improve_skill("martial-cognize", 1500000);
                	me->set("can_perform/pixie-jian/pi", 1);
        	}
               	me->receive_damage("jing", 80);
               	me->add("learned_points", 10);
               	me->start_busy(2);
                return 1;
	}

        // ��а����������Ԫ��
        if (pfm == "po")
	{
	        if ((int)me->query("can_perform/pixie-jian/po"))
	        {
        	        write("���Ѿ�ѧ�������У����о�Ҳû�á�\n");
                	return 1;
	        }

	        if (! (int)me->query_skill("pixie-jian"))
	        {
        	        write("���о��˰��죬�������������صľ���������޹�ϵ��\n");
                	return 1;
	        }

        	if ((int)me->query_skill("pixie-jian", 1) < 180)
	        {
        	        write("�㷢�������ϼ��صľ��й�����£�һʱ�������ס�\n");
                	return 1;
	        }

        	if (random(50) < 48)
        	{
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
                	tell_object(me, HIY "��Ա�а�������˸������⣬�������һ"
                                       "�����о���\n" NOR);
        	} else
        	{ 
                	message_vision(HIR "$N" HIR "��ϸ���ж������ϼ��صľ��У���"
                                       "������\n" NOR, me);
	                tell_object(me, HIY "�������ã���Ȼ����˫Ŀһ��������������"
                                        "�����������صı�а������������Ԫ�񽣡��İ�"
                                        "�أ�\n" NOR + HIC "��ѧ���ˡ���Ԫ�񽣡���\n" NOR);

	                if (me->can_improve_skill("sword"))
        	                me->improve_skill("sword", 1500000);
	                if (me->can_improve_skill("dodge"))
        	                me->improve_skill("dodge", 1500000);
	                if (me->can_improve_skill("parry"))
        	                me->improve_skill("parry", 1500000);
                	if (me->can_improve_skill("pixie-jian"))
                        	me->improve_skill("pixie-jian", 1500000);
              		me->improve_skill("martial-cognize", 1500000);
                	me->set("can_perform/pixie-jian/po", 1);
        	}
               	me->receive_damage("jing", 80);
               	me->add("learned_points", 10);
               	me->start_busy(2);
                return 1;
	}
}
