inherit ROOM;

void create()
{
        set("short", "ʮ����");
        set("long", @LONG
����һ���ܴ��б�£��׳�ʮ���̣���ʯ��һ��һ����ֱ
���ϣ��ķѽ����������������񣬹չ�����������ʮ��֮��
����������
LONG);
        set("exits", ([
                "northdown" : __DIR__"shiliang",
                "southup" : __DIR__"shijie2",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
