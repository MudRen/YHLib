#include <ansi.h>
inherit ITEM;

void create()
{
       set_name(HIW "ǧ����" NOR, ({"qianri zui", "qianri", "zui"}));
       set("unit", "��");
       set("long", HIW "����һ�ź��Ҵ�С�Ĺ�ʵ��ɢ����һ��Ũ���ľ��㡣\n" NOR);
       set("value", 200);
       set_weight(50);
       setup();
}
