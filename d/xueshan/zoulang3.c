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
                "west"  : __DIR__"neidian",
                "south" : __DIR__"zoulang1",
        ]));
        setup();
        replace_program(ROOM);
}
