inherit ROOM;

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
С��¥�ϱ��Ƕ����ɵĲؾ����ˡ����ﶼ���������飬��
���������ܡ����������Ŵ����ӣ����Ϸ��˼����𾭡��и�
Сʦ̫�����򾲵�ʦ̫���顣
LONG);
        set("objects", ([
                CLASS_D("emei") + "/dao" : 1,
                __DIR__"obj/fojing1" + random(2) : 1,
                __DIR__"obj/fojing2" + random(2) : 1,
        ]));

        set("exits", ([
                "down"  : __DIR__"chuwujian", 
        ]));
        setup();
        replace_program(ROOM);
}
