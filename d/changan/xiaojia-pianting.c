//Room: xiaojia-pianting.c

inherit ROOM;

void create ()
{
        set ("short", "ƫ��");
        set ("long", @LONG
���������ҵ�ƫ����������ǻ���������Ѿ��æ����ͣ���ƺ�����
ʲô���¡�
LONG);
        set("exits", ([
        	"south" : __DIR__"xiaojiadt",
        ]));

        set("objects", ([
        	__DIR__"npc/yahuan" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
