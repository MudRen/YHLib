#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(HIW "��ɽѩ����" NOR, ({ "xuelian gao", "gao", "xuelian", "lian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����ɽѩ������������ҩ�������Ƶ���ҩ��\n" NOR);
                set("base_unit", "��");
                set("base_value", 20000);
                set("base_weight", 100);
                set("only_do_effect", 1);
                set("pill_skill", "dodge");
                set("pill_point", 33000);
                set("force_point", 50);
                set("pill_msg1", HIW "��ֻ�е�����֮��ɢ��ȫ��˵������������á�\n" NOR);
                set("pill_msg2", HIC "��ֻ����̨�������ޱȣ������õ�����ȫ�Ĳ��䡣\n" NOR);
        }
        setup();
}
