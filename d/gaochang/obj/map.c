#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL "�߲��Թ���ͼ" NOR, ({ "map", "ditu" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "\n����һ�Ÿ߲��Թ���ͼ������ͼʾ�������·�λ���ɽ��롣\n\n" HIW
                            "����������������������������������������������\n"
                            "������" NOR + HIR "��" NOR + HIW "��" NOR + HIR "��" NOR + HIW
                            "��" NOR + HIR "��" NOR + HIW "��" NOR + HIR "��" NOR + HIW "��"
                            NOR + HIR "��" NOR + HIW "��" NOR + HIR "��" NOR + HIW "��" NOR +
                            HIR "��" NOR + HIW "��" NOR + HIR "��" NOR + HIW "��" NOR + HIR
                            "��" NOR + HIW "������\n"
                            "����������������������������������������������\n\n" NOR);
                set("value", 10);
                set("material", "paper");
        }
}

