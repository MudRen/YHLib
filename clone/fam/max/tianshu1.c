#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "���������项" NOR, ({ "wangqing tianshu", "wangqing", "tianshu" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "��˵�е����飬����ȴ���������з��ա�\n" NOR);
                set("value", 500000);
                set("unit", "��");
        }
}

void init()
{
        add_action("do_read", "read");
}

int do_read(string arg)
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (me->is_fighting())
                return notify_fail("ս�����޷��ж���\n");

        if (arg && id(arg))
        {
                if (me->query("skybook/guard/death") >= 1
                   || me->query("combat_exp") > 2500000)
                        return notify_fail(HIW "\n�����ᷭ����ҳ��ͻȻ��һ��ǿ"
                                           "��������ʲô�����������\n" NOR);

                log_file("static/using", sprintf("%s(%s) use �������� at %s.\n",
                                                 me->name(1), me->query("id"),
                                                 ctime(time())));

                message_vision(HIY "$N" HIY "���ᷭ��" + query("name") + HIY "��"
                               "ҳ����ʱ��һ���⻪����$P" HIY "�����ӡ�\n" NOR, me);

                tell_object(me, HIC "ڤڤ�����ƺ��ܵ���ĳ�ֵ����ϣ����յ�һ�з�"
                                "�ս������Ŵ�����\n" NOR);

                me->add("skybook/guard/death", 1);
                me->start_busy(10);
                destruct(this_object());
                return 1;
        }
}

int query_autoload()
{
        return 1;
}