#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(NOR + WHT "�Ż�����" NOR, ({ "jiuhuan xizhang", "jiuhuan",
                                              "xizhang", "zhang" }) );
        set_weight(8000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + WHT "����һ��ͨ����ڵ����ȣ����ּ�Ϊ��"
                            "�أ��ǳ����ͣ�������\n�������ഫ��ʥ�����"
                            "��ͭ��������������Ž�������פ�ա�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "ȡ���Ż������������У���ʱ"
                                 "�𲨵����������߷�����\n" NOR);
                set("unwield_msg", HIW "$N" WHT "΢΢һЦ�������еľŻ���"
                                 "�ȷŻذ��ҡ�\n" NOR);
                set("stable", 100);
        }
        init_staff(180);
        setup();
}
