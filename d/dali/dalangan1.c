inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ�ô��������������ڴ˽���һ���൱��ĸ�������
��������һ��Ȧ��ʮ��ͷţ���Աߵ�¥���޵��Ŀ�������
���Ǳ��ص������˼ҡ�
LONG);
        set("objects", ([
                "/clone/quarry/yang2" : 2,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "west" : __DIR__"nongtian4",
                "up"   : __DIR__"dalangan2",
        ]));
        setup();
        replace_program(ROOM);
}
