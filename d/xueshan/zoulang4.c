inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ѩɽ���ڵ����ȡ������е��İ����컨������
һЩ��֪��ȷ�к���ĵ�̣�ǽ�������Ǻ�ͨ�׵ķ𾭹�
�±ڻ��ˡ����ϵ��ż���󺣵�������
LONG);
        set("exits", ([
                "east"  : __DIR__"neidian",
                "south" : __DIR__"zoulang2",
        ]));
        setup();
        replace_program(ROOM);
}
