#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(HIC "ǧ��ѩ����" NOR, ({ "xuelian gao", "gao", "xuelian", "lian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "��ǧ��ѩ������������ҩ�������Ƶ���ҩ��\n" NOR);
                set("base_unit", "��");
                set("base_value", 30000);
                set("base_weight", 100);
                set("only_do_effect", 1);
                set("pill_skill", "dodge");
                set("pill_point", 50000);
                set("force_point", 100);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}
