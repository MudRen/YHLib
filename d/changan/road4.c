inherit  ROOM;

void  create  ()
{
        set("short",  "��ٵ�");
        set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ��������
�ǣ�������ֱ�ﳤ���ǡ�
LONG);
        set("exits",  ([
                "west" :  __DIR__"dong-chengmen",
                "east" :  __DIR__"road3",
        ]));
        set("outdoors", "changan");
        setup();
        replace_program(ROOM);
}
