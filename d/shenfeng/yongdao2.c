inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
�߹��˳���һ�������������ӳ���˵�Ӱ�ӣ���ʱ����
�帹�����׻������������ϣ���ƽ����֮�棬ʵ�Դ�ʱΪ���ˡ�
LONG);
        set("exits", ([
                "north" : __DIR__"yongdao3",
        ]));

        setup();
        replace_program(ROOM);
}
