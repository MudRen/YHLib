inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
�������Ա��и�����Ȫ����˵��ǰ������ˮ�˶��˶��ɺԣ�
����Ϊ֮�о�������Ȫˮ���������������ֱ��Ƕù�̨���Ա�
���ǻ����֡�
LONG);
        set("objects", ([
                CLASS_D("emei") + "/xuan" : 1,
        ]));
        set("outdoors", "emei");
        set("exits", ([
                "northeast" : __DIR__"jinding", 
                "southeast" : __DIR__"duguangtai", 
        ]));
        setup();
        replace_program(ROOM);
}
