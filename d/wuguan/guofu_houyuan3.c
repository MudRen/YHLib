inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ���ˣ����ܶ��ǲ˵أ������Ǹ�Сɽ�£�����
�涼�������Χ��Ĳ˵أ����Ÿ����Ĳˣ���ʺ����ã�ҡҡ
��׹����������ûʲô�˴���
LONG);
        set("no_fight", 1);
        set("exits", ([
              "west" : __DIR__"guofu_caidi2",
              "east" : __DIR__"guofu_caidi1",
              "south" : __DIR__"guofu_houyuan2",
        ]));
        set("outdoors", "xiangyang");
        setup();
        replace_program(ROOM);
}
