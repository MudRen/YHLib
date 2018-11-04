#include <ansi.h>
inherit ROOM;

#define JIASHA    "/clone/lonely/book/kuihua1"

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ǻ�ɽ��ɽ�Ķ���ɽ�£����Ϸ����ǻ�ɽ����������Ⱥ�ľ��ң���
�ҵĴ������������ͷ����
LONG);
        set("exits",([
                "east" : __DIR__"songlin4",
        ]));
        setup();
}

void init()
{
        object me = this_player(), ob;

        ob = find_object(JIASHA);
        if (! ob) ob = load_object(JIASHA);

        add_action("do_look", "view");
       	add_action("do_look", "wang");

        if (! environment(ob) &&
	    ! query("begin") &&
            ! query("over") &&
            me->query("gender") == "����")
        {
		set("jiasha", 1);
                tell_object(me, HIB "��յ������Ȼ�����Ϸ��������������"
                                "������볯������(view)ȥ��\n" NOR);
        }
        return 0;
}

int do_look(string arg)
{
        object me = this_player();

        if (arg != "window" && arg != "chuanghu" && arg != "chuang")
                return notify_fail("��Ҫ��ʲô��\n");

        if (query("over") || ! query("jiasha"))
                return notify_fail("һ�Ƚ����ŵĴ�����ûʲô���Ƶġ�\n");

        if (query("begin"))
                return notify_fail("������������Ӱ����̸����Ҫ͵���ͱ𶯡�\n");

        if (me->query("gender") != "����")
                return notify_fail("һ�Ƚ����ŵĴ�����ûʲô���Ƶġ�\n");

        message_vision(HIB "$N" HIB "��������ȥ��ֻ����ǰ����������������Ӱ������"
                       "����ϸ�$N" HIB "���Ͳ�ס���棬����\n���ߵ���ǰ͵������"
                       "�ĶԻ���\n" NOR,me);
        remove_call_out("do_talk1");
        call_out("do_talk1", 4, me);
        set("begin", 1);
        me->start_busy(43);
        return 1;
}

int do_talk1(object me)
{
        message_vision( WHT "\nֻ����һλŮ�ӵ�����˵������ʦ�磬�Ҿ����������ɫ"
                        "���ԣ��ǲ���������ϼ����\nЩ���鷳���ɱ�̫�󾫽����ǳ�"
                        "�����������������ƺ��ǻ�ɽ���ŷ���������\n" NOR, me);
        remove_call_out("do_talk2");
        call_out("do_talk2", 4, me);
        return 1;
}

int do_talk2(object me)
{
        message_vision( WHT "\n������һλ��������������˵������û�а���������˳��"
                        "�úܡ�����������ϡ���ǻ�ɽ\n����������Ⱥ���㲻�����һ��"
                        "��\n" NOR, me);
        remove_call_out("do_talk3");
        call_out("do_talk3", 4, me);
        return 1;
}

int do_talk3(object me)
{
        message_vision( WHT "\n��Ů���ֵ�����������ң�Ϊ��ô�����˵����ɤ�ӱ���"
                        "���ּ��ָߣ�����Ů���Ƶġ���\n" NOR, me);
        remove_call_out("do_talk4");
        call_out("do_talk4", 4, me);
        return 1;
}

int do_talk4(object me)
{
        message_vision( WHT "\n������ŭ��������˵�˵�����˵���������������ġ���\n"
                        NOR, me);
        remove_call_out("do_talk5");
        call_out("do_talk5", 4, me);
        return 1;
}

int do_talk5(object me)
{
        message_vision( HIB "\n������������˵��仰��ɤ����Ȼ�൱�⣬ȷ���Ǹ�Ů��"
                        "�ڴ�Ƣ����\n" NOR, me);
        remove_call_out("do_talk6");
        call_out("do_talk6", 4, me);
        return 1;
}

int do_talk6(object me)
{
        message_vision( WHT "\n��Ů�ӽ���˵��������˵û�䣿��һ��֮�У��ʹ���û��"
                        "������˵�����������򸾶��꣬\n����������ô�ⲻ�����£���"
                        "�����ң���\n" NOR, me);
        remove_call_out("do_talk7");
        call_out("do_talk7", 4, me);
        return 1;
}

int do_talk7(object me)
{
        message_vision( WHT "\n�������ֵ���������ô�ⲻ�����£��ţ���ɽ֮�᲻Զ��"
                        "��������ͼ�̲����ɣ�������\nȻ���ҡ���Ϊ�˷��ģ���Ҳ����"
                        "�ġ���\n" NOR,me);
        remove_call_out("do_talk8");
        call_out("do_talk8", 4, me);
        return 1;
}

int do_talk8(object me)
{
        message_vision( WHT "\n��Ů�Ӻ���һ�����������ҿ�����ֹ�ڴˡ���\n" NOR, me);
        remove_call_out("do_talk9");
        call_out("do_talk9", 4, me);
        return 1;
}

int do_talk9(object me)
{
        message_vision( WHT "\n�����Ӽ��������������Ϲ���ģ����������ô����\n"
                        NOR, me);
        remove_call_out("do_talk10");
        call_out("do_talk10", 4, me);
        return 1;
}

int do_talk10(object me)
{
        message_vision( WHT "\n��Ů������ʮ��ƽ����˵��������˵�˳�������ɱ𷢻�"
                        "����֪������ԩ���˳������\n�ճ�����˻��ԣ�������ֹѪ��"
                        "��֮ʱ�������������м����ģ�д�����֣��ƺ��ǽ���\n֮�ࡣ"
                        "�ڶ���������ҩ���Ǽ������Ѿ������ˣ���ʱ�����Ȼ����δ��"
                        "�����ʱ��֮�У�\n�������Ҷ��ˣ����ޱ��˽�����������Ŀ�"
                        "�������õġ���\n" NOR, me);
        remove_call_out("do_talk11");
        call_out("do_talk11", 6, me);
        return 1;
}

int do_talk11(object me)
{
        message_vision( WHT "\n�����Ӽ��β��˵��������ֻ���������˵��һ�����֣�"
                        "��û��˵��ȥ����\n" NOR, me);
        remove_call_out("do_talk12");
        call_out("do_talk12", 4, me);
        return 1;
}

int do_talk12(object me)
{
        message_vision( WHT "\n��Ů��������ת��ͣ�˵������ʦ�磬�һ�ɽһ�ɵĽ���"
                        "�����ж��������裬��ϼ��\n���������ǲ������Դ���������"
                        "�����������������ڽ�����ԭ������ȥ��ѧ���ɽ�����\nֻ�ǽ�"
                        "��������Ұ�Ĵ�㣬ͼ�����ɡ���ɽһ���������˵��ôҲ��"
                        "��������������\n�С�������������̩ɽ����ɽ����ɽ���ɣ���"
                        "ʱ�����ɶ���һ�ɣ��ҿ�����ռ������Ӯ\n�棬������Ĳ�ʤ��"
                        "����������ҵľ綷һ����������������ɽ��Ҳ�����ˣ�����"
                        "��\nȪ֮��Ҳ�������Ի�ɽ�ɵ��������ڡ���\n" NOR, me);
        remove_call_out("do_talk13");
        call_out("do_talk13", 6, me);
        return 1;
}

int do_talk13(object me)
{
        message_vision( WHT "\n�����Ӵ�������������֪����ѧ��а�������㡭���㡭��"
                        "��͵�����𣿡�\n" NOR, me);
        remove_call_out("do_talk14");
        call_out("do_talk14", 4, me);
        return 1;
}

int do_talk14(object me)
{
        message_vision( WHT "\n��Ů��˵���������ֺα�͵�����֪������˵����������"
                        "���Ѿ�ȫȻ���ˣ����˶�����\n�������ѵ����Լ����������ã�"
                        "ÿ���糿���㱻�������������������롭����\n" NOR, me);
        remove_call_out("do_talk15");
        call_out("do_talk15", 4, me);
        return 1;
}

int do_talk15(object me)
{
        message_vision( WHT "\n�����Ӽ��һ�����ʵ��������Ƽ��ˣ��������Ǿ�������"
                        "\n" NOR, me);
        remove_call_out("do_talk16");
        call_out("do_talk16", 4, me);
        return 1;
}

int do_talk16(object me)
{
        message_vision( WHT "\n��Ů��̾�����������Ƽ��ˣ�һֱ��˵����ճ�ļ��룬��"
                        "�������ˣ�ȴ�����ù�������\n�˼�ʮ����޵����֮�ˣ���\n"
                        NOR,me);
        remove_call_out("do_talk17");
        call_out("do_talk17", 4, me);
        return 1;
}

int do_talk17(object me)
{
        message_vision( WHT "\n�����Ӽ����Ѱ�¶���޿��ٱ磬�������ã��ʵ���������"
                        "����˭֪���ˣ���\n" NOR, me);
        remove_call_out("do_talk18");
        call_out("do_talk18", 4, me);
        return 1;
}

int do_talk18(object me)
{
        message_vision( WHT "\n��Ů��˵������û�У�ɺ����ƽ֮Ҳ��֪����\n" NOR, me);
        remove_call_out("do_talk19");
        call_out("do_talk19", 4, me);
        return 1;
}

int do_talk19(object me)
{
        message_vision( WHT "\n�����ӳ���Ƭ�̣�˵�������ã��������Ȱ��������ģ�"
                        "��������ȥ���������뷨����\n����ϴˢ��ס���·���������"
                        "Ҳ�����ˡ���\n" NOR, me);
        remove_call_out("do_talk20");
        call_out("do_talk20", 4, me);
        return 1;
}

int do_talk20(object me)
{
        object ob;
        int exp, pot, sc;

        exp = 10000 + random(3000);
        pot = 1000 + random(300);
        sc = random(50);

        ob = find_object(JIASHA);
        if (! ob) ob = load_object(JIASHA);

        if (! environment(ob))
	{
        	message_vision( HIR "\n$N" HIR "���һ�������������ֹ�������˲���֮�"
                               "���������к�������������Ȩ��ȥ����\n�ڴ�ʱ��ֻ���ô���ѽ"
                               "��һ���򿪣�$N" HIR "��æ��ͷ����ǰ���һ�����Ǽ�����Ʈ"
                               "����������\n���Ŵ����ּ����ϡ��ۿ������Ĵ�����Ʈ����$N" HIR
                               "����һץ���������ߣ�û��ץ������ʱ\n$N" HIR "��������֮"
                               "���⣬���ִ������ϣ������������һ����ֻ���ż��ƺ�������"
                               "���ģ���\n�������������������˵ý������������Ĺ����ˣ�û"
                               "��������Ͽ�µ�������Ԩ�С�\n\n" NOR, me);
	        set("over", 1);
        	delete_temp("jiasha");
	        ob->move(me, 1);

                if (! (int)me->query("skybook/xiaoao/baodian"))
                {
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
                        me->add("score", sc);
                        tell_object(me, HIW "��ɹ���ȡ���˿������䣡\n" NOR + HIC "ͨ"
                                        "����ε�������������" + chinese_number(exp) +
                                        "�㾭�顢" + chinese_number(pot) + "��Ǳ\n���Լ�"
                                        + chinese_number(sc) + "�㽭��������\n\n" NOR);
                        me->set("skybook/xiaoao/baodian", 1);
                } else
        	        tell_object(me, HIC "��õ���һ�����ġ�\n\n" NOR);
	} else
	{
        	message_vision( HIR "\n$N" HIR "���һ�������������ֹ�������˲���֮�"
                               "���������к�������������Ȩ��ȥ����\n�ڴ�ʱ��ֻ���ô���ѽ"
                               "��һ���򿪣�$N" HIR "��æ��ͷ����ǰ���һ�����Ǽ�����Ʈ"
                               "����������\n���Ŵ����ּ����ϡ��ۿ������Ĵ�����Ʈ����$N" HIR
                               "����һץ���������ߣ�û��ץ��������\n��ʱ��������Ͽ�µ���"
                               "����Ԩ�С�\n\n" NOR, me);
	        set("over", 1);
        	delete_temp("jiasha");
	}
        return 1;
}
