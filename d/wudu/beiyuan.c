inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǳ�Ժ��Ժ���ﾲ���ĵġ�������һ��������ԶԶƮ��һ��
���㣬���Ǹÿ����ˡ�  
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"bingqi",
                "south" : __DIR__"lianwu",
                "north" : __DIR__"chufang",
        ]));

        setup();
}
