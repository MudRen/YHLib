inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
������Ȼ�Ǻ�Ժ�����治ʱ������˻�����㿴��ȥ������
�Ǹ���������������Ҳ�ǳ����ģ������Ǿ�ľͷ��������
LONG);
        set("no_fight", 1);
        set("exits", ([
              "west" : __DIR__"guofu_mafang",
              "east" : __DIR__"guofu_mufang",
              "south" : __DIR__"guofu_houyuan",
              "north" : __DIR__"guofu_houyuan3",

        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
