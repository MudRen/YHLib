#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + YEL "����о�ɢ" NOR, ({ "xingjun san", "xingjun", "san" }));
        set("unit", "��");
        set("long", NOR + YEL "����һ��Ԥ��������ҩɢ���������Ͽ���Ԥ��������\n" NOR);
        set("no_sell", "����ɶ���������Ҳ����Ǯ��");
        set("value", 1);
        set_weight(200);        
        setup();
}