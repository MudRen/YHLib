inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
���������е�һƬ�յأ����ܱ�����Ĺ��ɻ����ţ�������һƬ
�����͵Ĳݵء��ݵ����������һ��ȭͷ��С��С�����Ա�����Բ
��ݲ�����¶�����ɫ������������һƬ�ž����ݵ����������ģ���
�������ȴһҲ�����ɣ�����ò�����ʲôΣ�հɣ�
LONG );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"sl7",
        ]));

        if (random(3) > 1)
                set("objects", ([
                        "/clone/beast/jinshewang" : 1,
                ]));

        setup();
        replace_program(ROOM);
}
