inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����ǹ����ĺ�Ժ������Щ�ɻ����µĵط��������ȥ��
�ǲ񷿣�������һ��ˮ��������æµ�Ľ����������Լ��Ļ
LONG);
        set("no_fight", 1);
        set("exits", ([
               "east" : __DIR__"guofu_chaifang",
               "west" : __DIR__"guofu_shuifang",
               "north" : __DIR__"guofu_houyuan2",
               "south" : __DIR__"guofu_shilu-3",
        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
