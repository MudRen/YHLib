#include <ansi.h>
inherit __DIR__"pill";

void create()
{
        set_name(NOR + YEL "������" NOR, ({ "sheli zi", "sheli", "zi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "���Ÿ�ɮ��Բ��ǰͨ��������������ע���������С�\n" NOR);
                set("base_unit", "��");
                set("base_value", 5000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("pill_skill", "etc");
                set("force_point", 5);
                set("pill_msg3", HIM "��е�������������һЩ��\n" NOR);
                set("pill_msg4", HIR "��е���Ϣ���ȣ���������ҩ����\n" NOR);
        }
        setup();
}
