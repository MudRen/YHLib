inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������ǵĳ��⣬����������ǰ���Ǹ��ʵĳ�ǽ������
������ӳ����ߣ���ҪԽǽ���룬�ǲ�̫���ܵġ���������Ұ��
�ܶ࣬���Բ���ʲô��ȫ�ĵط������ǸϿ���ǰɡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
                "west" : __DIR__"shanya",
        ]));
        set("objects", ([
                "/clone/quarry/lang" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
