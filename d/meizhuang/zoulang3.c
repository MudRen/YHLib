inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����������ȣ�������������λׯ���е�������λƽʱ��
Ϣ�������ĵط�����߾���÷ׯ�ĳ��������ȵ��������ƺ��͵��˾�
ͷ������ǰ����÷ׯ�ĺ����ˡ�
LONG
        );
        set("exits", ([
            "north" : __DIR__"houting",
            "south" : __DIR__"zoulang2",
            "west"  : __DIR__"chufang",  
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

