inherit ROOM;

void create()
{
    set("short", "ǰԺ");
    set("long", @LONG
��������վ��һ������Ժ���С�Ժ��ԭ������Ϊ���䳡
�õġ����Դ��һ������ӱ���ҩʦ������⣬��û���ڴ����䡣
�����Ǳ����ң������ǳ������������һ�ɽׯ������
LONG);
    set("exits", ([
        "north" : __DIR__"damen",
        "south" : __DIR__"dating",
        "east"  : __DIR__"bingqi",
        "west"  : __DIR__"chufang",
    ]));
    set("outdoors", "taohua");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
