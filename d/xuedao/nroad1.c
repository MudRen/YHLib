inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ����᫵�ɽ·����ӵ�������Ͳ�������ȥ�ˡ�ɽ
·�����Ӳݴ�����·��ʼԽ��Խ���ߡ�ɽ·Խ��Խխ��������
����ǰ���ֳַ��˼�����·��
LONG);
        set("exits", ([
                "west"  : __DIR__"nroad2",
                "south" : __DIR__"nroad0",
                "north" : __DIR__"nroad5",
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

