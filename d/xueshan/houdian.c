inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ����µĺ�Ҳ��ѩɽ���ӱ��������ĵط�����
����һЩ���������ź�ľ�ˣ�����һЩ�����ŵ�ɳ����ֱ����
ľ׮��
LONG);

        set("exits", ([
                "north" : __DIR__"chanshi",
                "south" : __DIR__"neidian",
        ]));

        setup();
        replace_program(ROOM);
}
