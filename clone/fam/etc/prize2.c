#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "�}�Tʿ����" NOR, ({ "chivalry medal", "chivalry", "medal" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "Ӣ��Ů���C�l�Ī��£��ƺ������u���Ãr�X��\n" NOR);
                set("unit", "ö");
                set("value", 500000);
        }
        setup();
}
