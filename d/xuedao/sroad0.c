inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·Խ��Խխ������������ǰ���ֳַ��˼�����·������
�ǿ��������ĳ�ɽ���룬��ʯ��ᾡ����������Ǵ�����Ե����
����һ��ѩɽ�������ơ�
LONG);
        set("exits", ([
                "south" : __DIR__"sroad3",
                "north" : __DIR__"nroad0",
        ]));
        set("outdoors", "xuedao");
        setup();
        replace_program(ROOM);
}

