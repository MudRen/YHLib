inherit ROOM;

void create()
{
        set("short", "ʯ�ݶ�");
        set("long", @LONG
ɽ·����ʯ�ݶ���ʯ�ݶ��������ж�������������������
������ྻ�������Ͽ���խ��״�縡�ݡ����ϱ㵽������¤
ɽ·�ľ�ͷ����һ���ɱ����ϵĴ����
LONG);
        set("exits", ([
                "westup"    : __DIR__"manjuelong",
                "east"      : __DIR__"road18",
        ]));
        set("objects", ([
                "/clone/worm/changaoxie": 1,
        ]));
        setup();
        replace_program(ROOM);
}

