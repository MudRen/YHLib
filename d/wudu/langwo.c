inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������е�һ����������������ζ�˱ǣ��洦���ǳ�
ʣ���޹ǲ�������ֻ�ݵ�Ƥ����ͷ�Ķ��������Ӿ����ƺ�Ҫ
��ȥ��ʳ�ˡ�
LONG);

        set("exits", ([
                "out" : __DIR__"milin4",
        ]));
        set("objects", ([
                "/clone/quarry/lang"  : 2,
                "/clone/quarry/lang2" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
