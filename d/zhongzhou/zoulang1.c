inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������Ŵ��ú�������ȣ�����������һСʯ���ţ�����
��һ��С��԰�����������������������޼����ݡ��������ȵ�
��ͷ���ſ��ţ���֪�ǲ��Ǿ���ʦү����
LONG);
        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"shiye",
                 
        ]));

        setup();
        replace_program(ROOM);
}

