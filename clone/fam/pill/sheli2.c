#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(NOR + CYN "��������" NOR, ({ "fozun sheli", "sheli", "fozun" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "���Ÿ�ɮ��Բ��ǰͨ��������������ע���������С�\n" NOR);
                set("base_unit", "��");
                set("base_value", 8000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("pill_skill", "etc");
                set("force_point", 12);
                set("pill_msg3", HIM "��е�������������һЩ��\n" NOR);
                set("pill_msg4", HIR "��е���Ϣ���ȣ���������ҩ����\n" NOR);
        }
        setup();
}
