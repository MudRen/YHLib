#include <armor.h>
inherit HANDS;
#include <ansi.h>;

void create()
{
        set_name(HIY "��˿����" NOR, ({ "jinsi shoutao", "shoutao", "jinsi" }));
        set_weight(2900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һ˫�ý�˿���ƶ��ɵ����ף�������������ȡ������������Ʒ�������ж���\n" NOR);
                set("unit", "˫");
                set("material", "iron");             
                set("value", 500);
                set("no_sell", "����Ҳ����\n");
                set("armor_prop/armor", 1);
        }
        setup();
}
