inherit ROOM;

void create()
{
        set("short", "��ţ��ݵ�����");
        set("long", @LONG
�����ǽ�ţ��ݵĵ����ң���Ȼ���ݣ���Ҳ���ֻ����
Щ�谵����ǽ�м����̵ĺúõĴ�����Щ��������Ϣ��
LONG );
        set("no_fight", 1);
        set("sleep_room", 1);
        set("exits", ([
                "up" : __DIR__"wuguan",
        ]));
        setup();
        replace_program(ROOM);
}
