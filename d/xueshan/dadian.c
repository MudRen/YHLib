inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ����µĴ����빩���ŷ�������ɮ��������
�ž��ģ������������������ʢ��Զ�����������������
��Ĥ�ݡ�������඼�ǲ�
LONG);
        set("exits", ([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects", ([
                CLASS_D("xueshan") + "/lazhang" : 1,
                __DIR__"npc/xiang-ke" : 2,
        ]));
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);

        "/clone/board/xueshan_b"->foo();
}
