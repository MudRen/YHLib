#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name( WHT "�����" NOR,  ({ "chiyou jian", "sword", "jian" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����������ĳ����������ϵ�����ȵ�ͷ��\n");
                set("value", 100000);
                set("material", "gold");
                set("wield_msg", HIR "$N" HIR "�������񽣻����˸�������ֻ�е�һ��"
                                 NOR + HIW "����" NOR + HIR "���������\n" NOR);
        }
        init_sword(200);
        setup();
}
