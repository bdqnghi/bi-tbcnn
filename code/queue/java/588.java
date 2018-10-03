package com.aimprosoft.wavilon.model;

import org.codehaus.jackson.annotate.JsonIgnoreProperties;
import org.codehaus.jackson.annotate.JsonProperty;

@JsonIgnoreProperties(value = {"maxTime", "maxLength", "forwardToOnMaxTime", "forwardToOnMaxLength", "musicOnHold"}, ignoreUnknown = true)
public class Queue extends BaseModel {
    @JsonProperty("max_time")
    private Integer maxTime;

    @JsonProperty("max_length")
    private Integer maxLength;

    @JsonProperty("forward_to_on_max_time")
    private String forwardToOnMaxTime;

    @JsonProperty("forward_to_on_max_length")
    private String forwardToOnMaxLength;

    @JsonProperty("music_on_hold")
    private Object musicOnHold;

    public Queue() {
    }

    public Integer getMaxTime() {
        return maxTime;
    }

    public void setMaxTime(Integer maxTime) {
        this.maxTime = maxTime;
    }

    public Integer getMaxLength() {
        return maxLength;
    }

    public void setMaxLength(Integer maxLength) {
        this.maxLength = maxLength;
    }

    public String getForwardToOnMaxTime() {
        return forwardToOnMaxTime;
    }

    public void setForwardToOnMaxTime(String forwardToOnMaxTime) {
        this.forwardToOnMaxTime = forwardToOnMaxTime;
    }

    public String getForwardToOnMaxLength() {
        return forwardToOnMaxLength;
    }

    public void setForwardToOnMaxLength(String forwardToOnMaxLength) {
        this.forwardToOnMaxLength = forwardToOnMaxLength;
    }

    public Object getMusicOnHold() {
        return musicOnHold;
    }

    public void setMusicOnHold(Object musicOnHold) {
        this.musicOnHold = musicOnHold;
    }
}


