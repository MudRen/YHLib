#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(NOR + RED "Ѫ����" NOR, ({ "xue puti", "xue", "puti" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "������������֮ʵ��������ɽ������ǰ����ϡ�ޱȡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 5000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("pill_skill", "force");
                set("force_point", 5);
                set("pill_msg3", HIM "��е��������ۺ���һЩ��\n" NOR);
                set("pill_msg4", HIR "��е���Ϣ���ȣ���������ҩ����\n" NOR);
        }
        setup();
}
