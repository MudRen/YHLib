// wudoumi-fanshi.c
// �嶷���񹦷���

#include <ansi.h>
inherit F_CLEAN_UP;

int dispel(object me, object ob, int duration)
{
        int f, n, lvl;
        f = me->query_skill_mapped("force");
        lvl = me->query_skill("force");

        if (me != ob)
        {
                tell_object(ob, "�㷢��" + me->name() + "������ԴԴӿ����ʹ��"
                            "�ﴦȼ�յø�Ϊ�������������ݺ�¯����ǰ��ʱһ�ڡ�\n");
                tell_object(me, "����ͼ����" + ob->name() + "��������������ȴ"
                            "���ֶԷ��������ƺ�¯���ѣ����ɴ󾪣���æס�֡�\n");

                if (living(ob))
                        ob->unconcious();

                return -1;
        }

        if (me->query_skill_mapped("force") != "yijin-duangu"
           && me->query_skill_mapped("force") != "jiuyin-shengong"
           && me->query_skill_mapped("force") != "shaolin-jiuyang"
           && me->query_skill_mapped("force") != "wudang-jiuyang"
           && me->query_skill_mapped("force") != "emei-jiuyang"
           && me->query_skill_mapped("force") != "jiuyang-shengong"
           && me->query_skill_mapped("force") != "taiji-shengong"
           && me->query_skill_mapped("force") != "xuanmen-neigong"
           && me->query_skill_mapped("force") != "xiantian-gong")
        {
                tell_object(me, "�����ȫ�����������¯���ѣ���Ϣ"
                                "�����޷����ۡ�\n");
                return -1;
        }

        n = me->query_condition("wudoumi-fanshi") - lvl / 15;
        if (n < 1)
                me->clear_condition("wudoumi-fanshi");
        else
                me->apply_condition("wudoumi-fanshi", n);

        tell_object(me, "��ĬĬ������" + to_chinese(f) + "��������"
                        "������������\n");

        return 1;
}

int update_condition(object me, int duration)
{
	int limit;

	if (! living(me) && (me->query("eff_qi") < 20 || me->query("eff_jing") < 10))
        {
                me->set_temp("��ϰ�嶷���񹦲�����������������Ѫ����");
		me->die();
		return 0;
	} else
        {
                me->receive_wound("qi", 20);
                me->receive_wound("jing", 10);

                if (me->query("max_neili"))
                        me->add("max_neili", -1);

		tell_object(me, HIR "����õ��ﴦ��ͬ���գ�ȫ�������ĵ�"
                                "��ֹ������Ҫ�������һ�㡣\n" NOR);
		message("vision", HIR + me->name() + HIR "��ɫ��죬�뷢"
                                  "����ȫ��ɢ���Ź�����������ס�Ĳ�����\n",
			          environment(me), me);
	}

        if (me->query("max_neili") < 1)
                me->set("max_neili", 0);

	me->apply_condition("wudoumi-fanshi", duration - 1);

	if (! duration)
                return 0;

	return 1;
}
