#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ǵ����Ķ��ˣ�����ȫ��Ũ�ܵ�֦Ҷ��ʪ������̦޺��
һ��΢�紵������Ҷ���������������������������ȥ��ֻ��
��һ�����Σ����뻹�ǸϿ���ȥ�ɡ�
LONG);
        set("outdoors", "city");
        set("item_desc", ([
                "tree" : GRN "\n����һ�þ޴���ϵĴ���"
                         "����֦Ҷ�ǳ���ï�ܡ�\n" NOR,
        ]));
        set("exits", ([
                "down" : __DIR__"guangchang",
        ]));
        set("objects", ([
               CLASS_D("xiakedao") + "/shi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
