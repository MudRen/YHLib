inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ��СС��ɽ����Ѫ������Ĳ���֮�ء���춴˵ر�
�����أ���Һ���Ѱ��������������һ�Ź��������湩��ʲ��
�������㿴���塣���ϻ���һЩģ�����������ͼ����Ҳ��֪
����Щʲô��
LONG);
        set("exits", ([
                "out" : __DIR__"shandong2",
                "east": __DIR__"xiuxishi",
        ]));
        set("objects", ([
                CLASS_D("xuedao")+"/laozu" : 1,
                __DIR__"npc/x_lama" : 2,
        ]));
	set("valid_startroom", 1);
        setup();
        replace_program(ROOM);

        "/clone/board/xuedao_b"->foo();
}
