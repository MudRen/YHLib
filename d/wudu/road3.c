inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
����һ�����ϵĻ��������Զ����Լ����һƬ���̵�ɽ�͡�·��
������ϡ����������·Խ��Խխ����Щ�ط���������һƬƬ���Ӳݡ�
�����ƺ���һ����·��
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "southeast" : __DIR__"xiaolu",
                "south" : __DIR__"shanlu1",
                "north" : __DIR__"road2",
        ]));

        setup();
        replace_program(ROOM);
}
