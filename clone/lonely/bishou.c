#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + CYN "����" WHT "ذ��" NOR, ({ "xuantie bishou", "xuantie", "bishou" }));
        set_weight(12000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + CYN "ͨ����ڵ�ذ�ף�ذ�����߳�˿˿��"
                            "�⡣\n" NOR);
                set("unit", "��");
                set("no_sell", "����ý����Ը����Űɡ�");
                set("value", 100000);
                set("material", "xuantie");
                set("wield_msg", HIR "$N" HIR "���һ���������ذ������"
                                 "���У���ʱһ�������������\n" NOR);
                set("unwield_msg", HIR "$N" HIR "�����е�ذ�ײ��ѥ�С�\n" NOR);
                set("stable", 100);
        }
        init_sword(200);
        setup();
}
