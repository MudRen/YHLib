inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
ɽ������һ��Ƭ�����أ�����������Ʈ�ż�����ƣ�����������
�͵Ĳݵأ�ǳǳ�ĸպÿ��Ըǹ����棬ɢ����һ�����˵ķ��������
��ֱ��������������ǰ���м����ª�����ᡣ
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"zhushe",
                "northdown" : __DIR__"shanlu3",
        ]));

        setup();
        replace_program(ROOM);
}
