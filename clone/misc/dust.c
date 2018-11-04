// dust.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + WHT "��ʬ��" NOR, ({ "dust" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", NOR + WHT "����һ���û�ʬ�𼣵Ļ�ʬ�ۣ�ֻ"
                            "Ҫһ����Ϳ��Ի�ȥ(" HIW "dissolve" NOR +
                            WHT ")һ��ʬ�塣\n" NOR);
                set("value", 50000);
        }
        setup();
}

void init()
{
        if (this_player() == environment())
                add_action("do_dissolve", "dissolve");
}

int do_dissolve(string arg)
{
        object ob;

        if (! arg)
                return notify_fail("��Ҫ�û�ʬ���ܽ�ʲô������\n");

        if (! objectp(ob = present(arg, environment(this_player()))))
                return notify_fail("����û������������\n");

        if (! ob->is_corpse() && ! ob->is_body_part() && ! ob->is_head())
                return notify_fail("��ʬ��ֻ�������ܽ�ʬ�塣\n");

        if (ob->query("defeated_by") && ob->query("defeated_by") != this_player())
                return notify_fail("���ʬ���ѱ����˶����ˣ����Ǳ�Ϊ�\n");

        message_vision(WHT "$N" WHT "��ָ������һ�㻯ʬ����$n"
                       WHT "�ϣ���ʱֻ�������͡�������ɢ����һ"
                       "�ɶ����\n" RED "����ζ����ɢ����ȴ��"
                       "$n" RED "��ʣ����һ̲��ˮ��\n" NOR,
                       this_player(), ob);
        destruct(ob);
        return 1;
}
