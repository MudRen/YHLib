inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������Ŵ��ú�������ȣ�����������һСʯ���ţ�����
��һ��С��԰�����������������������޼����ݡ��������ȵ�
��ͷ���ſ��ţ���֪�ǲ��Ǿ���ʦү��.
LONG);

        set("exits", ([
                "west" : __DIR__"huayuan",
                "north" : __DIR__"zoulang1",
                "east"  : __DIR__"yamen",

        ]));

        setup();
        replace_program(ROOM);
}
