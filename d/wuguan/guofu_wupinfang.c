#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��Ʒ��");
        set("long", @LONG
������Ʒ����һ������ӡ�����ŵ��������룬��������
�Ĺܼ��Ǻ����渺��ģ�һЩ�����ڸ�����Ʒ���ߵ�����˵��
ʲô��
LONG);
        set("no_fight", 1);
        set("exits", ([
               "south" : __DIR__"guofu_lang4",
               "north" : __DIR__"guofu_lang6",
               "west" : __DIR__"guofu_shilu-1",
        ]));
        set("objects", ([
           	__DIR__"npc/wuxiuwen" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
