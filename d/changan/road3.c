inherit  ROOM;

void  create()
{
        set("short", "��ٵ�");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��������
�ǣ�������ֱ�ﳤ���ǡ�
LONG);
        set("exits",  ([
                "west" :  __DIR__"road4",
                "east" :  __DIR__"zhongnan",
        ]));
        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
