//Room: xiaojia-sleep.c

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG
���������ҵ����ң�������ǻ���������Ѿ��æ����ͣ���ƺ�����
ʲô���¡�
LONG);
        set("exits", ([
        	"north" : __DIR__"xiaojiadt",
        ]));
        set("objects", ([
        	__DIR__"npc/yahuan" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
